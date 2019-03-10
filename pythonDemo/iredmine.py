#!/usr/bin/env python
# -*- coding: utf-8 -*-
from __future__ import print_function
from numpy import *
import pycurl, StringIO, urllib, sys, re, datetime, time, getpass


IRedmineLogin = "http://iredmine"
LoginHeaders = list()
LoginHeaders.append("Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8")
LoginHeaders.append("Accept-Encoding: gzip, deflate")
LoginHeaders.append("Accept-Language: zh-CN,zh;q=0.9")
LoginHeaders.append("Cache-Control: max-age=0")
LoginHeaders.append("Connection: keep-alive")
LoginHeaders.append("Content-Type: application/x-www-form-urlencoded")
LoginHeaders.append("Host: iredmine")
LoginHeaders.append("Origin: http://iredmine")
LoginHeaders.append("Referer: http://iredmine/login?back_url=http%3A%2F%2Firedmine%2F")
LoginHeaders.append("Upgrade-Insecure-Requests: 1")




EmployeeInfoUrl = "http://oa-center/Programs/KQ/EmployeeInfoStatistic.aspx";
OAUrl = "http://oa-center/Programs/login/login.aspx";
EmployeeReqUrl = "http://oa-center/Programs/KQ/EmployeeRequestOvertime.aspx";
HolidayUrl = "http://api.goseek.cn/Tools/holiday?date=";
headList = list()
headList.append("Accept:text/html,application/xhtml+xm…plication/xml;q=0.9,*/*;q=0.8")
headList.append("Cache-Control:max-age=0")
headList.append("Accept-Encoding:gzip, deflate")
headList.append("Accept-Language:zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2")
headList.append("Connection:keep-alive")
headList.append("Content-Type:application/x-www-form-urlencoded")
headList.append("Upgrade-Insecure-Requests:1")
headList.append("Host:oa-center")
cookieContext = list()


def LoginIredmine():
    iStr = GetHttp(IRedmineLogin)
    print ("text  ===  " + iStr)

    # headList.append("Referer:" + OAUrl)
    # Map = GetPageInputValue(GetHttp(OAUrl))
    # Map["tbPassword"] = Pwd
    # Map["tbUserName"] = User
    # loginInfo = PostHttp(OAUrl, headList, urllib.urlencode(Map))

    # if loginInfo.find("用户名或密码不正确") != -1:
    #     print ('pwd or name error !!')
    #     exit(1)
    # if loginInfo.find('密码已经过期，请先修改密码') != -1:
    #     print ('密码已经过期，请先修改密码 !!')
    #     exit(1)
    # GetCookie(loginInfo)

def GetHttp(url):
    buf = StringIO.StringIO()
    curl = pycurl.Curl()
    curl.setopt(pycurl.HTTPHEADER, headList)
    curl.setopt(pycurl.URL, url)
    curl.setopt(pycurl.WRITEFUNCTION, buf.write)
    curl.setopt(pycurl.COOKIEFILE, '')
    curl.setopt(pycurl.HEADER, True)
    curl.setopt(pycurl.CONNECTTIMEOUT, 5)
    curl.setopt(pycurl.FOLLOWLOCATION, 1)
    curl.setopt(pycurl.SSL_VERIFYPEER, False)
    curl.setopt(pycurl.SSL_VERIFYHOST, False)
    curl.setopt(pycurl.NOSIGNAL, True)
    curl.perform()

    pageText = buf.getvalue()
    buf.close()

    # print (pageText)
    if not curl.getinfo(pycurl.HTTP_CODE) == 200:
        print ("Get http error !! ")
        print (curl.getinfo(pycurl.HTTP_CODE))
    return pageText  

def PostHttp(url, headerList, body = ''):
    buf = StringIO.StringIO()
    curl = pycurl.Curl()
    curl.setopt(pycurl.HTTPHEADER, headerList)
    if not body == '':
        curl.setopt(pycurl.POST, True)
        curl.setopt(pycurl.POSTFIELDS, body)
        curl.setopt(pycurl.POSTFIELDSIZE, len(body))
        curl.setopt(pycurl.HEADER, True)
    curl.setopt(pycurl.URL, url)
    curl.setopt(pycurl.WRITEFUNCTION, buf.write)
    curl.setopt(pycurl.CONNECTTIMEOUT, 5)
    curl.setopt(pycurl.FOLLOWLOCATION, 1)
    curl.setopt(pycurl.SSL_VERIFYPEER, False)
    curl.setopt(pycurl.SSL_VERIFYHOST, False)
    curl.setopt(pycurl.NOSIGNAL, True)
    curl.perform()

    pageText = buf.getvalue()
    buf.close()

    # print (pageText)
    if not curl.getinfo(pycurl.HTTP_CODE) == 200:
        print ("Post http error !! ")
        print (curl.getinfo(pycurl.HTTP_CODE))
    return pageText

def GetPageInputValue(pageText):
    # inputList = re.compile(r'/<input\s+[^>]*?name\s*=\s*(\'|\")(.*?)\\1[^>]*?value\s*=\s*(\'|\")(.*?)\\1[^>]*?\/?\s*>/i').findall(pageText)
    nameValueMap = dict()
    inputList = re.compile(r'<input\s*(.*?)\/>', re.S|re.M).findall(pageText)
    for inputStr in inputList:
        nameStr = ''
        valueStr = ''
        nameObj = re.search( r'name\s*=\s*\"(.*?)\"', inputStr, re.M|re.S)
        if nameObj:
            nameStr = nameObj.group(1)
        valueObj = re.search( r'value\s*=\s*\"(.*?)\"', inputStr, re.M|re.S)
        if valueObj:
            valueStr = valueObj.group(1)
        if not nameStr == '':
            nameValueMap[nameStr] = valueStr
    return nameValueMap

def GetCookie(cookie):
    cookieObj = re.search(r'Set-Cookie:\s*(.*?)\;', cookie, re.M|re.S)
    if cookieObj:
        cookieContext.append(cookieObj.group(1))

def isHoliday(date):
    headerList = list()
    headerList.append("Accept:text/html,application/xhtml+xm…plication/xml;q=0.9,*/*;q=0.8")
    headerList.append("Cache-Control:max-age=0")
    headerList.append("Accept-Encoding:gzip, deflate")
    headerList.append("Accept-Language:zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2")
    headerList.append("Connection:keep-alive")
    headerList.append("Content-Type:application/x-www-form-urlencoded")
    headerList.append("Upgrade-Insecure-Requests:http://api.goseek.cn/")
    headerList.append("Host:api.goseek.cn")
    headerList.append("Referer:http://api.goseek.cn/")

    dataObj = re.search( r'data":(\d*)', PostHttp(HolidayUrl + date, headerList), re.M|re.S)
    if dataObj:
        return dataObj.group(1)
    print ("get holiday data error!!")
    return -1

def beginMakeMoney(arr, row):
    overTimeData = list()
    for i in xrange(row):
        date = arr[i, 0]
        beginTime = arr[i, 3]
        endTime = arr[i, 4]
        reason = arr[i, 8]

        __startTime = ''
        __overTime = ''
        if not beginTime == '' and not endTime == '' and not date == '':
            #实际加班终止时间戳
            stopDateTime = time.mktime(time.strptime(endTime, "%H:%M:%S"))
            startDateTime = time.mktime(time.strptime("18:50:00", "%H:%M:%S"))
            actualTime = time.mktime(time.strptime("18:30:00", "%H:%M:%S"))
            # 判断是xx:30:xx 还是xx:00:xx
            normalTime = time.mktime(time.strptime("00:30:00", "%H:%M:%S"))
            hoildayStartDateTime = time.mktime(time.strptime(beginTime, "%H:%M:%S"))

            # =======================终止时间=======================
            if 0 < (stopDateTime - normalTime)/60%60 <=30: # 0 ~ 30 表示时间取半小时
                temp = time.strftime("%H:%M:%S", time.localtime(int(str((stopDateTime - normalTime)/3600).split(".")[0]) * 3600 + 1800 + normalTime))
                __overTime = temp.split(":")[0] + ":" + temp.split(":")[1]
            else:
                temp = time.strftime("%H:%M:%S", time.localtime(int(str((stopDateTime - normalTime)/3600).split(".")[0]) * 3600 + 3600 + normalTime))
                __overTime = temp.split(":")[0] + ":" + temp.split(":")[1]

            if isHoliday(date) == '0': # 上班日
                if (stopDateTime - startDateTime) > 0: # 个人加班时间从六点五十开始
                    # =======================起始时间=======================
                    if reason.find("年假") != -1:
                        total = (stopDateTime - hoildayStartDateTime) / 3600 - 5.5
                    else:
                        total = (stopDateTime - hoildayStartDateTime) / 3600 - 9.5
                    overTimeData.append(date)
                    overTimeData.append(date)
                    overTimeData.append("18:30")
                    overTimeData.append(__overTime)
                    overTimeData.append(total)
            else: # 双休日或者法定节假日
                if 0 < (hoildayStartDateTime - normalTime) / 60 % 60 <= 30:
                    temp = time.strftime("%H:%M:%S", time.localtime(int(str((hoildayStartDateTime - normalTime)/3600).split(".")[0]) * 3600 + normalTime))
                    __startTime = temp.split(":")[0] + ":" + temp.split(":")[1]
                else:
                    temp = time.strftime("%H:%M:%S", time.localtime(int(str((hoildayStartDateTime - normalTime)/3600).split(".")[0]) * 3600 + 1800 + normalTime))
                    __startTime = temp.split(":")[0] + ":" + temp.split(":")[1]

                total = (stopDateTime - hoildayStartDateTime) / 3600
                overTimeData.append(date)
                overTimeData.append(date)
                overTimeData.append(__startTime)
                overTimeData.append(__overTime)
                overTimeData.append(total)

    DisplayYouGetMoney(overTimeData)

def Login(User, Pwd):
    headList.append("Referer:" + OAUrl)
    Map = GetPageInputValue(GetHttp(OAUrl))
    Map["tbPassword"] = Pwd
    Map["tbUserName"] = User
    loginInfo = PostHttp(OAUrl, headList, urllib.urlencode(Map))

    if loginInfo.find("用户名或密码不正确") != -1:
        print ('pwd or name error !!')
        exit(1)
    if loginInfo.find('密码已经过期，请先修改密码') != -1:
        print ('密码已经过期，请先修改密码 !!')
        exit(1)
    GetCookie(loginInfo)

def GetEmployeeInfo():
    del headList[8]
    headList.append("Cookie:" + cookieContext[0])
    headList.append("Referer:" + EmployeeInfoUrl)

    selectMonth = raw_input('\nSelect this month(Any key to continue) or last month(n)...')
    if selectMonth == 'n':
        Map = GetPageInputValue(GetHttp(EmployeeInfoUrl))
        Map["TimeSelect"] = "RadioButtonPREV_MONTH"
        Map["InfoSelect"] = "RadioButtonPUNCH_CARD_INFO"
        DisplayEmployeeInfo(PostHttp(EmployeeInfoUrl, headList, urllib.urlencode(Map)))
    else:
        DisplayEmployeeInfo(GetHttp(EmployeeInfoUrl))

def DisplayEmployeeInfo(info):
    tableObj = re.search(r'<table.*?>(.*?)<\/table>', info, re.M|re.S)
    if tableObj:
        tableStr = tableObj.group()
        spanList = re.compile(r'<span.*?>(.*?)<\/span>', re.S|re.M).findall(tableStr)
        #通过numpy将list转化为array以便进行数学处理
        spanArray = array(spanList)
        spanArrayRow = len(spanArray)/9
        #将array转化为9×(len(array/9))的矩阵
        spanArray.shape = spanArrayRow,9

        print("\n===================================================================Payroll============================================================================\n\n");
        print("       日期                星期         刷卡次数         出勤刷卡             离勤刷卡        迟到(分钟)     早退(分钟)    旷工（小时）     事由\n")
        for i in xrange(spanArrayRow):
            # 刷卡次数为零不打印
            if not spanArray[i,2] == '0':
                for j in xrange(9):
                    if j == 8:
                        print ("     " + spanArray[i,j])
                    else:
                        print ("     " + spanArray[i,j], end = '        ')
        print("\n==========================================================================================================================================================\n\n")
        beginMakeMoney(spanArray, spanArrayRow)

def DisplayYouGetMoney(data):
    total = 0
    dataArray = array(data)
    dataArrayRow = len(dataArray)/5
    dataArray.shape = dataArrayRow,5
    print ("===============================================加班详情======================================================\n\n")
    print ("        开始日期               结束日期             开始时间          结束时间         加班时长(h)\n")
    for i in xrange(dataArrayRow):
        for j in xrange(5):
            if j == 4:
                temp = str(dataArray[i,j])[0:6]
                total = total + double(temp)
                print ("       " + temp)
            else:
                print ("       " + dataArray[i,j], end = '      ')
    print ("\n      Not enough, keep working hard                                                      " + str(total)[0:6])
    print ("\n============================================================================================================\n\n")
    PutMoneyInYourPocket(dataArray, dataArrayRow)

def PutMoneyInYourPocket(arr, row):
    del headList[9]
    headList.append("Referer:" + EmployeeReqUrl)
    select = raw_input('\nIs the amount correct?(Any key to continue) or incorrect(n)...')
    if select == 'n':
        exit(1)

    reason = raw_input('\nHow to make money:')
    btnAddLineStatus = GetPageInputValue(GetHttp(EmployeeReqUrl))
    for i in xrange(row):
        Map = dict()
        Map["__VIEWSTATEGENERATOR"] = btnAddLineStatus["__VIEWSTATEGENERATOR"]
        Map["__VIEWSTATE"] = btnAddLineStatus["__VIEWSTATE"]
        Map["__EVENTVALIDATION"] = btnAddLineStatus["__EVENTVALIDATION"]
        Map["TextBoxREASON"] = reason
        Map["TextBoxDATE_FROM"] = arr[i, 0]
        Map["DropDownListTIME_FROM"] = arr[i, 2]
        Map["TextBoxDATE_TO"] = arr[i, 1]
        Map["DropDownListTIME_TO"] = arr[i, 3]
        Map["btnAddLine"] = "添加明细"

        btnPostStatus = GetPageInputValue(PostHttp(EmployeeReqUrl, headList, urllib.urlencode(Map)))
        Map["__VIEWSTATEGENERATOR"] =  btnPostStatus["__VIEWSTATEGENERATOR"]
        Map["__VIEWSTATE"] = btnPostStatus["__VIEWSTATE"]
        Map["__EVENTVALIDATION"] = btnPostStatus["__EVENTVALIDATION"]
        Map["btnPost"] = "提交"
        PostHttp(EmployeeReqUrl, headList, urllib.urlencode(Map))
        print ("Get more money ... ")
        time.sleep(1)

if __name__ == '__main__':
    # user = raw_input('please input you name:')
    # pwd = getpass.getpass('please input you pwd:')
    # if user == '' or pwd == '':
    #     print ('name or pwd is empty !!')
    #     exit(1)

    LoginIredmine()
