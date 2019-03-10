#include"TransferPython.h"
#include<python2.7/Python.h>
#include"ProjectDef.h"

TransferPython::TransferPython() :
    m_after(""),
    m_Before("")
{

}

void TransferPython::setAfterAndBefore(const QString &After, const QString &Before)
{
    m_after = After.toStdString();
    m_Before = Before.toStdString();
    std::cout<<m_after<<" + "<<m_Before<<std::endl; //log

    if(transferPythonToMsg()) {
        std::string msg = QPROJECT_FINISHED;
        emit notifyServiceMergeMsg(msg);
    }
}

bool TransferPython::transferPythonToMsg()
{
    if(m_after == "" || m_Before == "") {
        std::string msg = QPROJECT_ERROR;
        emit notifyServiceMergeMsg(msg);
        return false;
    }

    Py_Initialize();

    if (!Py_IsInitialized()) {
        std::cout<<"initialize is failed ..."<<std::endl;
        return false;
    }

    PyRun_SimpleString(QIMPORT_SYS);
    PyRun_SimpleString(QPYTHONFILE_PATH);

    PyObject *pModule, *pDict, *pFunc, *pArgs;
    pModule = PyImport_ImportModule(QPYTHONFILE_NAME);

    if (!pModule) {
        std::cout<<"can't find file ..."<<std::endl;
        return false;
    }

    pDict = PyModule_GetDict(pModule);

    if (!pDict) {
        std::cout<<"can't find dictionary"<<std::endl;
        return false;
    }

    pFunc = PyDict_GetItemString(pDict, "merge_excel");
    if (!pFunc || !PyCallable_Check(pFunc)) {
        std::cout<<"can't find function [add]"<<std::endl;
    }

    //  PyObject* Py_BuildValue(char *format, ...)
    //  把C++的变量转换成一个Python对象。当需要从
    //  C++传递变量到Python时，就会使用这个函数。此函数
    //  有点类似C的printf，但格式不同。常用的格式有
    //  s 表示字符串，
    //  i 表示整型变量，
    //  f 表示浮点数，
    //  O 表示一个Python对象
    *pArgs;
    pArgs = PyTuple_New(2);
    PyTuple_SetItem(pArgs, 0, Py_BuildValue("s", m_after.c_str()));
    PyTuple_SetItem(pArgs, 1, Py_BuildValue("s", m_Before.c_str()));

    PyObject_CallObject(pFunc, pArgs);

    Py_DECREF(pArgs);
    Py_DECREF(pModule);

    // 关闭Python
    Py_Finalize();
    return true;
}
