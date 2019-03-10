#include<python2.7/Python.h>
#include<iostream>
#include<string>

using namespace std;

void printDict(PyObject* obj)
{
    if(!PyDict_Check(obj))
        return ;

    PyObject *k, *keys;
    keys = PyDict_Keys(obj);

    for(int i=0; i < PyList_GET_SIZE(keys); i++)
    {
        k = PyList_GET_ITEM(keys, i);
        char *c_name = PyString_AsString(k);
        printf("%s\n", c_name);
    }
}

int main(void)
{
    Py_Initialize();
    if(!Py_IsInitialized())
        return -1;

    PyRun_SimpleString("import sys");
    //where you put your py file
    PyRun_SimpleString("sys.path.append('./')");
    //Import
    PyObject* pModule = PyImport_ImportModule("pc");//no *.py
    if(!pModule)
    {
        printf("can't open python file!\n");
        return -1;
    }
    //Dict module
    PyObject* pDict = PyModule_GetDict(pModule);
    if(!pDict)
    {
        printf("can't find dictionary.\n");
        return -1;
    }
    printDict(pDict);

    PyObject *pFunHi = PyDict_GetItemString(pDict, "sayHi");
    PyObject_CallFunction(pFunHi, "s", "yourname");// @para1: obj, @para2: name
    //release
    Py_DECREF(pFunHi);

    //Contruct a obj , call it's function
    //Second Class
    PyObject *pClassSecond = PyDict_GetItemString(pDict , "Second");
    if(!pClassSecond)
    {
        printf("can't find second class.\n");
        return -1;
    }
    //Person Class
    PyObject *pClassPerson = PyDict_GetItemString(pDict, "Person");
    if(!pClassPerson)
    {
        printf("can't find Person class.\n");
        return -1;
    }
    //Construct Second Instance
    PyObject* pInstanceSecond = PyInstance_New(pClassSecond, NULL, NULL);
    if(!pInstanceSecond)
    {
        printf("can't create second instance.\n");
        return -1;
    }
    //Construct Person Instance
    PyObject *pInstancePerson = PyInstance_New(pClassPerson, NULL, NULL);
    if(!pInstancePerson)
    {
        printf("can't create Person instance.\n");
        return -1;
    }

    //pass Person Instance to Second Instance
    PyObject_CallMethod(pInstanceSecond, "invoke", "O", pInstancePerson);
    PyObject_CallMethod(pInstanceSecond, "method2", "O", pInstancePerson);

    //call execute a py file
    PyRun_SimpleString("exec(compile(open('./1.py').read(),'1.py', 'exec'),locals(), globals())");
    //release
    Py_DECREF(pInstanceSecond);
    Py_DECREF(pInstancePerson);
    Py_DECREF(pClassSecond);
    Py_DECREF(pClassPerson);
    Py_DECREF(pModule);
    Py_Finalize();

    return 0;
}
