#!/usr/bin/env python
# -*- coding: utf-8 -*-


import os, sys, os.path, re, math

CLEAR_VARS = 'CLEAR_VARS'
STATIC_LIBRARIES = 'STATIC_LIBRARIES'
BUILD_PREBUILT = 'BUILD_PREBUILT'

LOCAL_MODULE_TAGS = 'LOCAL_MODULE_TAGS'
LOCAL_MODULE_TAGS_REPLACE = 'LOCAL_MODULE_TAGS := optional\n'

LOCAL_MODULE_SUFFIX = 'LOCAL_MODULE_SUFFIX'
LOCAL_UNINSTALLABLE_MODULE = 'LOCAL_UNINSTALLABLE_MODULE := true\n'

def ProcessNutshell(BinaryPath):
    bFindSpace = False
    for root, dirs, files in os.walk(BinaryPath):
        for filename in files:
            if not filename.endswith('.mk'):
                continue
            pathname =  os.path.join(root, filename)
            with open(pathname,"r") as f_r:
                lines = f_r.readlines() 
            with open(pathname,"w") as f_w:
                for line in lines:
                    if line.find(STATIC_LIBRARIES) != -1:
                        bFindSpace = True
                    if line.find(BUILD_PREBUILT) != -1:
                        bFindSpace = False
                    if bFindSpace:
                        if LOCAL_MODULE_TAGS in line:
                            line = LOCAL_MODULE_TAGS_REPLACE
                        if LOCAL_MODULE_SUFFIX in line:
                            f_w.write(line)
                            f_w.write('\n')
                            f_w.write(LOCAL_UNINSTALLABLE_MODULE)
                            continue
                    f_w.write(line)


if __name__ == '__main__':
    if not (len(sys.argv) == 2) :
        print('param error exit!')
        exit(1)

    BinaryPath = sys.argv[1]
    if os.path.exists(BinaryPath):
        print ('二进制仓库路径 ：' + BinaryPath)

        

    ProcessNutshell(BinaryPath)
    print ('Processing Over !')

