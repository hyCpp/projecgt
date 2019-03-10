class Person:
    def sayHi(self):
        print 'Hi'

class Second:
    def invoke(self, obj):
        obj.sayHi()
    def method2(self, obj):
        print "this is method2"

def sayHi(name):
    print 'Hi ,', name
