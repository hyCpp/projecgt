#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os, sys, os.path, re

def copyFiles(source, target):
    for i in os.listdir(source):
        source_ = os.path.join(source, i);
        target_ = os.path.join(target, i);

        print source_
        print target_

        if os.path.isfile(source_):
            if not os.path.exists(target):
                os.makedirs(target)
            if not os.path.exists(target_) or (os.path.exists(target_) and (os.path.getsize(source_) != os.path.getsize(target_))):
                open(target_, "wb").write(open(source_, "rb").read())
            else :
                pass

        if os.path.isdir(source_):
            copyFiles(source_, target_)


def regexChange(file, regex, repaceStr):
    if not os.path.isfile(file):
        print("path error :%s\n", file)
        return ""

    str = open(file, "r").read()

    if(str):
        str = regex.sub(repaceStr,  str)
        fout = open(file,  "w")
        fout.write(str)
        fout.close()


def insertStr(str, new, pos):
    return str[:pos] + "\n    " + new + str[pos:]


def addFunction(file, param, pos):
    if not os.path.isfile(file):
        print("path error :%s\n", file)
        return ""

    if (-1 == param.find(",")):
        print("param error\n")
        return ""

    str = open(file, "r").read()
    type = param.split(",")[0]
    valueName = param.split(",")[1]

    setFunc = "void setxxx(TYPE xxx);"
    setFunc = setFunc.replace("TYPE", type).replace("xxx", valueName)
    getFunc = "TYPE getxxx();"
    getFunc = getFunc.replace("TYPE", type).replace("xxx", valueName)
    param = "TYPE xxx;"
    param = param.replace("TYPE", type).replace("xxx", valueName)

    if(str):
        if (pos == 0):
            pos = str.find("setGetFunc") + len("SetGetFunc")

        if (pos == -1) :
            print("add func error :%s\n", file)
            return ""

        str = insertStr(str, setFunc, pos)
        pos = pos + len(setFunc) + 5
        str = insertStr(str, getFunc, pos)
        index2 = str.find("param:") + len("param:")
        str = insertStr(str, param, index2)

        fout = open(file,  "w")
        fout.write(str)
        fout.close()
        return pos + len(getFunc) + 5


if __name__ == '__main__':
    print sys.argv
    module = ''
    if (len(sys.argv) == 2) :
        exampleName = sys.argv[1]

    if (len(sys.argv) >= 3) :
        module = sys.argv[1]
        exampleName = sys.argv[2]

    path = os.getcwd()   #返回当前工作目录
    basePath = os.path.dirname(path) #返回上级目录
    appPath = os.path.dirname(basePath) + '/' + module.lower() + '/' + exampleName.lower() + '/'

    if os.path.exists(appPath):
       selectDelete = raw_input('Delete Old ' + module + exampleName + ' code ? (y or n): ')
       if (selectDelete == 'n'):
           print('Generate Fail exit!')
           exit(1)

    copyFiles(os.getcwd() + '/Temp', appPath)

    regexChange(appPath + 'xxxModel.h', re.compile('xxx'), module + exampleName)
    regexChange(appPath + 'xxxModel.h', re.compile('XXX'), module.upper() + exampleName.upper())

    flag = 0
    for p in range(3, len(sys.argv)):
        flag = addFunction(appPath + 'xxxModel.h', sys.argv[p], flag)

    os.rename(appPath + 'xxxModel.h', appPath + module + exampleName + 'Model.h')

    regexChange(appPath + 'xxxModel.cpp', re.compile('xxx'), module + exampleName)
    regexChange(appPath + 'xxxModel.cpp', re.compile('XXX'), module.upper() + exampleName.upper())
    os.rename(appPath + 'xxxModel.cpp', appPath + module + exampleName + 'Model.cpp')

    print("create code successfully!!")
