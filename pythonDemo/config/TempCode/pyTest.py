#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os, re, os.path

path = os.getcwd()
#print path
basepath = os.path.dirname(path)

basepath1 = os.path.dirname(basepath)

#print basepath, basepath1


def insertStr(str, new, pos):
    return str[:pos] + "\n    " + new + str[pos:]

testStr = "这些方法实现了string模块的大部分方法，如下表所示列出了目前字符串内建支持的方法，所有的方法都包含了对Unicode的支持，有一些甚至是专门用于Unicode的。 "

index = testStr.find("string")

testStr = insertStr(testStr, " demo", index)
#print testStr

param = "std::string,Name"

param1 = param.split(",")[0]
print param1
param2 = param.split(",")[1]
print param2
