#!/usr/bin/env python
# -*- coding: utf-8 -*-


import os, sys, os.path, re, math

CLEAR_VARS = 'CLEAR_VARS'
BUILD_PREBUILT = 'BUILD_PREBUILT'
LOCAL_IS_HOST_MODULE = 'LOCAL_IS_HOST_MODULE'
LOCAL_STRIP_MODULE = "LOCAL_STRIP_MODULE"
LOCAL_STRIP_REPLACE = 'LOCAL_STRIP_MODULE :=\n'

def ProcessNutshell(BinaryPath):
    bFindSpace = False
    isHost = False
    for root, dirs, files in os.walk(BinaryPath):
        for filename in files:
            if not filename.endswith('.mk'):
                continue
            pathname =  os.path.join(root, filename)
            print (pathname)
            with open(pathname,"r") as f_r:
                lines = f_r.readlines() 
            with open(pathname,"w") as f_w:
                for line in lines:
                    if line.find(CLEAR_VARS) != -1:
                        bFindSpace = True
                    if line.find(BUILD_PREBUILT) != -1:
                        bFindSpace = False
                        isHost = False
                    if line.find(LOCAL_IS_HOST_MODULE) != -1:
                        strip = line.strip('\n').split("=")
                        if len(strip) > 1:
                            if strip[1].strip() == 'true':
                                isHost = True
                    if bFindSpace and isHost:
                        if LOCAL_STRIP_MODULE in line:
                            line = LOCAL_STRIP_REPLACE
                            f_w.write(line)
                            print ('replace ok!!')
                            continue
                    f_w.write(line)


if __name__ == '__main__':
    if not (len(sys.argv) == 2) :
        print('param error exit!')
        exit(1)

    selectDelete = raw_input('请确认二进制仓库路径是否正确 ? (y or n): ')
    if (selectDelete == 'n'):
        print('Generate Fail exit!')
        exit(1)

    BinaryPath = sys.argv[1]
    if os.path.exists(BinaryPath):
        print ('二进制仓库路径 ：' + BinaryPath)


    ProcessNutshell(BinaryPath)
    print ('Processing Over !')
