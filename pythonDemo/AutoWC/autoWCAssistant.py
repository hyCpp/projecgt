#!/usr/bin/python
#coding=utf8
import itchat, time, requests, json
from itchat.content import *

@itchat.msg_register('Text')
def textMsgReply(msg):

    return (u"主人暂时不在, 小秘 :{}".format(autoRobot(msg['Text'])))


@itchat.msg_register([PICTURE, RECORDING, ATTACHMENT, VIDEO])
def downloadFiles(msg):
    msg.download(msg.fileName)
    typeSymbol = {
        PICTURE: 'img',
        VIDEO: 'vid', }.get(msg.type, 'fil')
    return '@%s@%s' % (typeSymbol, msg.fileName)


@itchat.msg_register(FRIENDS)
def addFriend(msg):
    msg.user.verify()
    msg.user.send('Nice to meet you!')


def autoRobot(text):
    url = "http://www.tuling123.com/openapi/api"

    data = {
        "key":"1089ddf28c3e40728638cb7913e39224",
        "info":text
    }

    resp = requests.post(url, data = data).json()

    return resp['text']


if __name__ == '__main__':
    itchat.auto_login(enableCmdQR=2)
    itchat.run(debug=True)
