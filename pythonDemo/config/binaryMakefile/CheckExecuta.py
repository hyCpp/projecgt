#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os, sys, os.path, re, math, xlwt, xlrd, xdrlib

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

yamlModuleList = []
sharelibflag = ['no', 'no', 'no']

def getAllPath():
    execl = xlrd.open_workbook('/home/huyang/MyDemo/config/binaryMakefile/frist.xlsm')
    table = execl.sheets()[0]
    _nrows = table.nrows
    _ncols = table.ncols

    for i in range(298,424):
        if table.row(i)[4].value == 'huyang':
            print table.row(i)[0].value
            CheckModule(table.row(i)[0].value)


def CheckModule(sourcePath):
    flag = False
    yamlModuleStr = ''
    staticModuleStr = ''
    moduleData = {}
    # moduleNameList = sourcePath.split('JA158')
    # modulePath = '/home/huyang/roke'+ moduleNameList[1]
    modulePath = '/home/huyang/iauto3/' + sourcePath
    print ('\n===========' + modulePath + '===========\n')
    for root, dirs, files in os.walk(modulePath):
        for filename in files:
            if not filename.endswith('.mk'):
                continue
            pathname =  os.path.join(root, filename)
            if pathname.find('test') != -1 or pathname.find('Test') != -1 or pathname.find('TEST') != -1 or pathname.find('tests') != -1:
                print ('\033[1;35mpassing : \033[0m ' + pathname)
                continue
            print ('\033[1;32madding  : \033[0m ' + pathname)
            staticModuleStr += pathname + '\n'

            lines = open(pathname, 'r').readlines()
            for line in lines:
                if line.find('#') != -1:
                    # if line.replace(' ','').find('include$(') != -1:
                    #     print ('warning : ' + line)
                    if line.strip().find('#') == 0:
                        continue
                    if line.find(LOCAL) > line.find('#') or line.find('include') > line.find('#'):
                        continue
                if line.find(CLEAR_VARS) != -1:
                    flag = True
                if line.find(BUILD_STATIC_LIBRARY) != -1:
                    flag = False
                    staticModuleStr += moduleData[LOCAL_MODULE]
                    staticModuleStr += moduleData.get(LOCAL_MODULE_TAGS, 'optional')
                    # print moduleData[LOCAL_MODULE]
                    # print moduleData[LOCAL_MODULE_TAGS]
                    # yamlModuleList.append('    - ' + moduleData[LOCAL_MODULE] + '.a\n')
                    moduleData.clear()
                if line.find(BUILD_EXECUTABLE) != -1:
                    flag = False
                    # yamlModuleList.append('    - ' + moduleData[LOCAL_MODULE] + '\n')
                    moduleData.clear()
                if line.find(BUILD_SHARED_LIBRARY) != -1:
                    # yamlModuleList.append('    - ' + moduleData[LOCAL_MODULE] + '.so\n')
                    moduleData.clear()
                if flag:
                    if line.find(LOCAL_MODULE) != -1 and line.find(LOCAL_MODULE_) == -1:
                        moduleData[LOCAL_MODULE] = line
                    if line.find(LOCAL_MODULE_TAGS) != -1:
                        # moduleName =  line.strip('\n').split("=")
                        # localModule = moduleName[1].split('#')
                        # moduleData[LOCAL_MODULE] = localModule[0].strip()
                        moduleData[LOCAL_MODULE_TAGS] = line


    # for i in range(len(yamlModuleList)):
    #     tempVar = yamlModuleList[i]
    #     yamlModuleStr+=yamlModuleList[i]


    # if yamlModuleStr.find('.so') == -1 and yamlModuleStr.find('.a') == -1:
    #     print ('============MODULE============= : ')
    #     print (yamlModuleStr)
    print staticModuleStr
    staticModuleStr = ''
    # del yamlModuleList[:]



if __name__ == '__main__':
    getAllPath()
    print ('')
