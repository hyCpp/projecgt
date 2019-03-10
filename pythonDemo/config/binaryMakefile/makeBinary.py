#!/usr/bin/env python
# -*- coding: utf-8 -*-

# version 2.4
# 修改时间：2018-06-08 12:19PM

# 修改了99行，动态库内容结束判断添加 find('include$(')
# 修复202行，yaml中include *的问题
# 修复135行，去掉头空格后，#为第一个则continue
# 修复197行，在make yaml时，只有目录中有test相关的路径过滤
# 改善debug输出美观
# 在template文件夹中添加新模板，如果存在proto和fbs，则添加GENHEADFILE模板   ps：生成文件还是手动的吧
# 修改201行，在yaml中添加.proto或者.fbs源文件
# 添加hpp过滤
# 添加107行BUILD_CUSTOM_TARGET提醒
# 修改了77行，增加了原仓库下tag不存在时候的默认赋值为optional
# v1.5    如果由proto或者fbs或者BUILD_PREBUILT则在yaml中添加GENHEADFILE或者BUILD_PREBUILT: ps：内容自己填写
# v1.6    修改了252行，对目标路径增加判空操作，若不存在则创建路径
# v1.7    修改了223行，对 .vendor.yaml 文件中的头文件外面加引号
#         例:      - "include/*.h"
# v1.8    增加了229行，头文件中列举出.hpp后缀的文件
# v1.9    增加了LOCAL_MODULE_变量，去除掉所有LOCAL_MODULE_类型的数据防止干扰LOCAL_MODULE的使用
# v2.0    增加了212,217-219,248-252行, 增加了MODULE是否有.so或.a的check，如果没有，则删除yaml中的HEADFILE部分，并输出Checking : Delete yaml HEADFILE because there is no .so or .a in MODULE!提示
# v2.1    修改了STATIC.mk模板，LOCAL_MODULE_TAGS固定位optional, 新增LOCAL_UNINSTALLABLE_MODULE := true
#         修正199-202行，当存在两个连续的SHARED_LIBRARY时，在中间添加新的一个空行
# v2.2    修正110行，添加LOCAL_MODULE := xxx，对LOCAL_MODULE在前面的判断。避免下面情况的做入
#         ALL_DEFAULT_INSTALLED_MODULES += $(addprefix $(TARGET_OUT)/usr/lib/,$(notdir $(LOCAL_MODULE).so))
# v2.3    add Leepi Android.bp
# v2.4    修正94行，当源mk中不存在LOCAL_MODULE_TAGS时，二进制mk中应默认为LOCAL_MODULE_TAGS := optional，而不是optional
# v2.5    1.添加HOST_EXECUTABLE\HOST_SHARED_LIBRARY\HOST_STATIC_LIBRARY的处理,并添加HOST的模板。
#         2.修正当headfile不存在时，去除.vendor.yaml中的HEADFILE:
#         3.修正当没有MODULE存在时，去除.vendor.yaml中的MODULE:
#         4.修改.vendor.yaml模板

import os, sys, os.path, re, math

CLEAR_VARS = 'CLEAR_VARS'
LOCAL_MODULE = 'LOCAL_MODULE'
LOCAL_SHARED_LIBRARIES = 'LOCAL_SHARED_LIBRARIES'
LOCAL_MODULE_TAGS = 'LOCAL_MODULE_TAGS'
BUILD_SHARED_LIBRARY = 'BUILD_SHARED_LIBRARY'
BUILD_EXECUTABLE = 'BUILD_EXECUTABLE'
BUILD_STATIC_LIBRARY = 'BUILD_STATIC_LIBRARY'
LOCAL_MODULE_PATH = 'LOCAL_MODULE_PATH'
DefaultModulePath = 'LOCAL_MODULE_PATH := $(TARGET_OUT)/usr/bin'
DefaultModulePathLib = 'LOCAL_MODULE_PATH := $(TARGET_OUT)/usr/lib'
LOCAL = 'LOCAL_'
LOCAL_MODULE_ = 'LOCAL_MODULE_'
BUILD_HOST_SHARED_LIBRARY = "BUILD_HOST_SHARED_LIBRARY"
BUILD_HOST_EXECUTABLE = "BUILD_HOST_EXECUTABLE"
BUILD_HOST_STATIC_LIBRARY = "BUILD_HOST_STATIC_LIBRARY"
LOCAL_MODULE_STEM = 'LOCAL_MODULE_STEM'
# variable that will be changed in the target
modulename = "module_variable"
moduletags = "tags_variable"
sharedlibs = "sharedlib_variable"
hostmodule = "host_variable"
stemmodule = "stem_variable"

moduleData = {}
yamlModuleList = []
yamlHostModuleList = []
sharelibflag = ['no', 'no', 'no']

def copyFiles(source, target):
    for i in os.listdir(source):
        source_ = os.path.join(source, i);
        target_ = os.path.join(target, i);

        if os.path.isfile(source_):
            if not os.path.exists(target):
#                os.makedirs(target)
                print ('binary is not exists :%s\n', target)
            if not os.path.exists(target_) or (os.path.exists(target_) and (os.path.getsize(source_) != os.path.getsize(target_))):
                if target_.find('nutshell.mk') != -1 or target_.find('.vendor.yaml') != -1:
                    open(target_, "wb").write(open(source_, "rb").read())
                    print ('product file : ' + target_ + '  success !!!')
            else :
                pass

        if os.path.isdir(source_):
            copyFiles(source_, target_)

def regexChangeFile(file, regex, repaceStr):
    if not os.path.isfile(file):
        print("path error :%s\n", file)
        return ""

    str = open(file, "r").read()

    if(str):
        str = regex.sub(repaceStr,  str)
        fout = open(file,  "w")
        fout.write(str)
        fout.close()

def regexChange(file, regex, repaceStr):
    if not os.path.isfile(file):
        print("path error :%s\n", file)
        return ''

    str = open(file, "r").read()

    if(str):
        str = regex.sub(repaceStr,  str)

    if LOCAL_MODULE_STEM in moduleData:
        if not moduleData[LOCAL_MODULE_STEM] == moduleData[LOCAL_MODULE] and not moduleData[LOCAL_MODULE_STEM] == '':
            moduleData[LOCAL_MODULE] = moduleData[LOCAL_MODULE_STEM]

    str = regexChangeStr(str, re.compile('yyyyyy'), moduleData.get(LOCAL_MODULE_TAGS, 'LOCAL_MODULE_TAGS := optional'))
    str = regexChangeStr(str, re.compile('hhhhhh'), moduleData[LOCAL_SHARED_LIBRARIES])
    str = regexChangeStr(str, re.compile('oooooo'), moduleData[LOCAL_MODULE_PATH])
    str = regexChangeStr(str, re.compile(moduletags), moduleData.get(LOCAL_MODULE_TAGS, 'LOCAL_MODULE_TAGS := optional'))
    str = regexChangeStr(str, re.compile(sharedlibs), moduleData[LOCAL_SHARED_LIBRARIES])
    str = regexChangeStr(str, re.compile(stemmodule), moduleData[LOCAL_MODULE])

    return str

def regexChangeStr(str, regex, repaceStr):
    if len(str) > 0:
        str = regex.sub(repaceStr,  str)
    return str

def dataFilter_mk(str, map):
    if str.find(LOCAL_MODULE) != -1 and str.find(LOCAL_MODULE_) == -1:

        str = str.strip('\n')
        moduleName =  str.split("=")
        if len(moduleName) > 1 and moduleName[0].find(LOCAL_MODULE) != -1:
            localModule = moduleName[1].split('#')
            map[LOCAL_MODULE] =  localModule[0].strip()
    if str.find(LOCAL_MODULE_TAGS) != -1:
        map[LOCAL_MODULE_TAGS] = str.strip('\n')
    if str.find('.proto') != -1:
        sharelibflag[1] = 'yes'
        print ('\033[1;35mwarning : \033[0m' + str)
    if str.find('.fbs') != -1:
        sharelibflag[1] = 'yes'
        print ('\033[1;35mwarning : \033[0m' + str)
    if str.find('BUILD_PREBUILT') != -1:
        sharelibflag[2] = 'yes'
        print ('\033[1;35mwarning : \033[0m' + str)
    if str.find('BUILD_CUSTOM_TARGET') != -1:
        print ('\033[1;35mwarning : \033[0m' + str)
    if str.find(LOCAL_MODULE_PATH) != -1:
        map[LOCAL_MODULE_PATH] = str.strip('\n')
    if str.find(LOCAL_MODULE_STEM) != -1:
        str = str.strip('\n')
        moduleStem =  str.split("=")
        if len(moduleStem) > 1 and moduleStem[0].find(LOCAL_MODULE_STEM) != -1:
            localModuleStem = moduleStem[1].split('#')
            map[LOCAL_MODULE_STEM] = localModuleStem[0].strip()
    if str.find(LOCAL_SHARED_LIBRARIES) != -1:
        sharelibflag[0] = 'yes'
    if str.count('\n')==len(str) or str.find('include $(') != -1 or (str.find(LOCAL) != -1 and str.find(LOCAL_SHARED_LIBRARIES) == -1):
        sharelibflag[0] = 'no'


def writeInFile(data, targetPath):
    file = targetPath
    if not os.path.isfile(file):
        print("path error :%s\n", file)
        return ''

    fout = open(file,  "a+")
    fout.write('\n' + data + '\n')
    fout.close



def produceMakeFile(sourcePath, targetPath):
    print ('\033[1;32mConfiguration nutshell.mk begin ... ! \033[0m')
    flag = False
    sharelibStr = ''
    for root, dirs, files in os.walk(sourcePath):
        for filename in files:
            if not filename.endswith('.mk') and filename.find("Android.bp") == -1:
                continue
            if not filename.find("Android.mk") == -1:
                continue
            pathname =  os.path.join(root, filename)
            if pathname.find('test') != -1 or pathname.find('Test') != -1 or pathname.find('TEST') != -1 or pathname.find('tests') != -1:
                print ('\033[1;35mpassing : \033[0m ' + pathname)
                continue
            print ('\033[1;32madding  : \033[0m ' + pathname)

            lines = open(pathname, 'r').readlines()
            for line in lines:
                if line.find('#') != -1:
                    if line.replace(' ','').find('include$(') != -1:
                        print ('warning : ' + line)
                    if line.strip().find('#') == 0:
                        continue
                    if line.find(LOCAL) > line.find('#') or line.find('include') > line.find('#'):
                        continue
                if line.find(CLEAR_VARS) != -1:
                    flag = True
                    moduleData[LOCAL_MODULE_PATH] = 'DefaultPath'
                    moduleData[LOCAL_SHARED_LIBRARIES] = ''
                if line.find(BUILD_STATIC_LIBRARY) != -1:
                    flag = False
                    writeInFile(regexChange(os.getcwd() + '/template/static.mk', re.compile('xxxxxx'), moduleData[LOCAL_MODULE]), targetPath + '/nutshell.mk')
                    yamlModuleList.append('    - ' + moduleData[LOCAL_MODULE] + '.a\n')
                    moduleData.clear()
                    sharelibStr = ''
                if line.find(BUILD_EXECUTABLE) != -1:
                    flag = False
                    if moduleData[LOCAL_MODULE_PATH] == 'DefaultPath':
                        moduleData[LOCAL_MODULE_PATH] = DefaultModulePath
                    moduleData[LOCAL_SHARED_LIBRARIES] = sharelibStr
                    writeInFile(regexChange(os.getcwd() + '/template/bin.mk', re.compile('xxxxxx'), moduleData[LOCAL_MODULE]), targetPath + '/nutshell.mk')
                    yamlModuleList.append('    - ' + moduleData[LOCAL_MODULE] + '\n')
                    moduleData.clear()
                    sharelibStr = ''
                if line.find(BUILD_SHARED_LIBRARY) != -1:
                    flag = False
                    if moduleData[LOCAL_MODULE_PATH] == 'DefaultPath':
                        moduleData[LOCAL_MODULE_PATH] = DefaultModulePathLib
                    moduleData[LOCAL_SHARED_LIBRARIES] = sharelibStr
                    if LOCAL_MODULE in moduleData:
                        writeInFile(regexChange(os.getcwd() + '/template/share.mk', re.compile('xxxxxx'), moduleData[LOCAL_MODULE]), targetPath + '/nutshell.mk')
                        yamlModuleList.append('    - ' + moduleData[LOCAL_MODULE] + '.so\n')
                    else:
                        print ('key is not exits')
                    moduleData.clear()
                    sharelibStr = ''
                if line.find(BUILD_HOST_SHARED_LIBRARY) != -1:
                    print ('\033[1;35mfind BUILD_HOST_SHARED_LIBRARY : %s! \033[0m ') % moduleData[LOCAL_MODULE]
                    flag = False
                    # Host do not need LOCAL_MODULE_PATH
                    moduleData[LOCAL_SHARED_LIBRARIES] = sharelibStr
                    if LOCAL_MODULE in moduleData:
                        writeInFile(regexChange(os.getcwd() + '/template/host_share.mk', re.compile(modulename), moduleData[LOCAL_MODULE]), targetPath + '/nutshell.mk')
                        yamlHostModuleList.append('    - ' + moduleData[LOCAL_MODULE] + '.so\n')
                    else:
                        print ('key is not exits')
                    moduleData.clear()
                    sharelibStr = ''
                if line.find(BUILD_HOST_EXECUTABLE) != -1:
                    print ('\033[1;35mfind BUILD_HOST_EXECUTABLE : %s! \033[0m ') % moduleData[LOCAL_MODULE]
                    flag = False
                    moduleData[LOCAL_SHARED_LIBRARIES] = sharelibStr
                    if LOCAL_MODULE in moduleData:
                        writeInFile(regexChange(os.getcwd() + '/template/host_bin.mk', re.compile(modulename), moduleData[LOCAL_MODULE]), targetPath + '/nutshell.mk')
                        yamlHostModuleList.append('    - ' + moduleData[LOCAL_MODULE] + '\n')
                    moduleData.clear()
                    sharelibStr = ''
                if line.find(BUILD_HOST_STATIC_LIBRARY) != -1:
                    print ('\033[1;35mfind BUILD_HOST_STATIC_LIBRARY : %s! \033[0m ') % moduleData[LOCAL_MODULE]
                    flag = False
                    if LOCAL_MODULE in moduleData:
                        writeInFile(regexChange(os.getcwd() + '/template/host_static.mk', re.compile(modulename), moduleData[LOCAL_MODULE]), targetPath + '/nutshell.mk')
                        yamlHostModuleList.append('    - ' + moduleData[LOCAL_MODULE] + '.a\n')
                    moduleData.clear()
                    sharelibStr = ''
                if flag:
                    dataFilter_mk(line, moduleData)
                    if sharelibflag[0] == 'yes':
                        if line.find(LOCAL_SHARED_LIBRARIES) != -1:
                            line = '\n' + line
                        else:
                            line = '    ' + line.strip() + '\n'
                        sharelibStr+=line
    if sharelibflag[1] == 'yes':
        genHeadFileStr = open(os.getcwd() + '/template/genheadfile.mk', 'r').read()
        writeInFile(genHeadFileStr, targetPath + '/nutshell.mk')
    return ('\033[1;32mConfiguration nutshell success ! \033[0m \n\n')



def produceYaml(sourcePath, targetPath):
    print ('\033[1;32mConfiguration .vendor.yaml begin ... ! \033[0m')
    yamlModuleStr = ''
    yamlHostModuleStr = ''
    yamlIncludeStr = ''
    bDeleteHeadfile = False
    yamlIncSet = set()

    for i in range(len(yamlHostModuleList)):
        yamlHostModuleStr+=yamlHostModuleList[i]

    for i in range(len(yamlModuleList)):
        yamlModuleStr+=yamlModuleList[i]

    if yamlModuleStr.find('.so') == -1 and yamlModuleStr.find('.a') == -1 and yamlHostModuleStr.find('.so') == -1 and yamlHostModuleStr.find('.a') == -1:
        bDeleteHeadfile = True
        print ('\033[1;35mChecking : Delete yaml HEADFILE because there is no .so or .a in MODULE! \033[0m ')


    for root, dirs, files in os.walk(sourcePath):
        for filename in files:
            if not filename.endswith('.h') and not filename.endswith('.fbs') and not filename.endswith('.proto') and not filename.endswith('.hpp'):
                continue
            pathname =  os.path.join(root, filename)
            if root.find('test') != -1 or root.find('Test') != -1 or root.find('TEST') != -1 or root.find('tests') != -1:
                print ('\033[1;35mpassing : \033[0m ' + pathname)
                continue
            print ('\033[1;32madding  : \033[0m ' + pathname)
            pathname = pathname.replace(sourcePath + '/', '    - \"')
            pathname = pathname.replace(sourcePath, '    - \"')
            pathname = re.sub("[\w-]+\.h", "*.h", pathname)
            pathname = re.sub("[\w-]+\.proto", "*.proto", pathname)
            pathname = re.sub("[\w-]+\.fbs", "*.fbs", pathname)
            pathname = re.sub("[\w-]+\.hpp", "*.hpp", pathname)
            pathname = pathname + '\"'

            yamlIncSet.add(pathname)
    for name in yamlIncSet:
        yamlIncludeStr += name + '\n'
    print ('INCLUDE : ')
    print (yamlIncludeStr)
    print ('MODULE : ')
    print (yamlModuleStr)
    print ('HOST_MODULE :')
    print (yamlHostModuleStr)

    if bDeleteHeadfile == False and len(yamlIncludeStr) != 0:
        regexChangeFile(targetPath + '/.vendor.yaml', re.compile('xxxx\n'), yamlIncludeStr)
    else:
        regexChangeFile(targetPath + '/.vendor.yaml', re.compile('HEADFILE:\n'), '')
        regexChangeFile(targetPath + '/.vendor.yaml', re.compile('xxxx\n\n'), '')

    if len(yamlHostModuleList) == 0:
        regexChangeFile(targetPath + '/.vendor.yaml', re.compile('HOST_MODULE:\n'), '')
        regexChangeFile(targetPath + '/.vendor.yaml', re.compile('host_variable\n'), '')
    else:
        regexChangeFile(targetPath + '/.vendor.yaml', re.compile('host_variable\n'), yamlHostModuleStr)

    if len(yamlModuleList) == 0:
        regexChangeFile(targetPath + '/.vendor.yaml', re.compile('NORMAL_MODULE:\n'), '')
        regexChangeFile(targetPath + '/.vendor.yaml', re.compile('oooo\n\n'), '')
    else:
        regexChangeFile(targetPath + '/.vendor.yaml', re.compile('NORMAL_MODULE:\n'), 'MODULE:\n')
        regexChangeFile(targetPath + '/.vendor.yaml', re.compile('oooo\n'), yamlModuleStr)

    if sharelibflag[1] == 'yes':
        writeInFile('GENHEADFILE:', targetPath + '/.vendor.yaml')
    if sharelibflag[2] == 'yes':
        writeInFile('PREBUILT_MODULE:', targetPath + '/.vendor.yaml')
    return ('\033[1;32mConfiguration .vendor.yaml success ! \033[0m')



if __name__ == '__main__':
    if not (len(sys.argv) == 3) :
        print('param error exit!')
        exit(1)

    targetPath = sys.argv[2]
    sourcePath = sys.argv[1]

    # 判断目标路径是否存在
    if not os.path.exists(targetPath):
        # 如果不存在则创建目录
        os.makedirs(targetPath)
        print ('\033[1;35m目标路径不存在,创建目录 : \033[0m ' + targetPath)


    if os.path.exists(targetPath) and os.path.exists(sourcePath):
        print ('二进制仓库路径 ：' + targetPath)
        print ('原代码仓库路径 ：' + sourcePath)
        selectDelete = raw_input('请确认二进制和代码仓库路径是否正确 ? (y or n): ')
        if (selectDelete == 'n'):
            print('Generate Fail exit!')
            exit(1)

    copyFiles(os.getcwd() + '/template', targetPath)
    print ('')
    print (produceMakeFile(sourcePath, targetPath))
    print (produceYaml(sourcePath, targetPath))

