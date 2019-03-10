#include "Simple.h"
#include "boost/shared_ptr.hpp"
#include "stdio.h"
#include <memory>
#include "smartpoint.h"
#include "weakPtrTest.h"
#include "../../LogConfig/Log_Func.cpp"
#include <map>

void CirculationError()
{
    std::shared_ptr<A> a(new A);
    std::shared_ptr<B> b(new B);
    a->s_pToB = b;
    b->s_pToA = a;
    a->printA();
    b->printB();
    LOGD("a use count is %d", a.use_count());
    LOGD("b use count is %d", b.use_count());
}

void WeakPointSolveCirculationError()
{
    std::shared_ptr<weakA> a(new weakA);
    std::shared_ptr<weakB> b(new weakB);
    a->s_pToWeakB = b;
    b->s_pToShareA = a;

    a->printWeakA();
    b->printWeakB();

    LOGD("a use count is %d", a.use_count());
    LOGD("b use count is %d", b.use_count());
}

void sharePtrTest()
{
    boost::shared_ptr<Simple> sp(new Simple(1));
    if (sp.get()) {
        sp->PrintSomething();
        sp.get()->info_extend = "Add";
        sp->PrintSomething();
        (*sp).info_extend += " other";
        sp->PrintSomething();
        boost::shared_ptr<Simple> sp2;
        sp2 = sp;
        sp->PrintSomething();
        sp2->PrintSomething();
        LOGD("sp is %d",sp.use_count());
        sp2.reset();
        LOGD("sp is %d",sp.use_count());
    }
}

void sharePtrRange()
{
    std::string* a = new string("test");

    LOGD("a = %s", (*a).c_str());

    {
        boost::shared_ptr<std::string> sp111(a);
    }

    if (!a) {
        LOGD("a not null %s", (*a).c_str());
    }
    else {
        LOGD("a is null %s", (*a).c_str());
    }

    delete a;
    a = nullptr;
}

Simple* getSimplePtr()
{
    boost::shared_ptr<Simple> ptr(new Simple(10));
    ptr->info_extend = "share_ptr";
    return ptr.get();
}

Simple* getSimplePtr1(boost::shared_ptr<Simple> ptr)
{
    ptr->info_extend = "share_ptr";

    return ptr.get();
}

boost::shared_ptr<Simple> getSimpleSmartPtr()
{
    boost::shared_ptr<Simple> ptr(new Simple(10));
    ptr->info_extend = "share_ptr";
    return ptr;
}

Simple getSimpleObject()
{
    boost::shared_ptr<Simple> ptr(new Simple(10));
    ptr->info_extend = "share_ptr";
    return *(ptr.get());
}

Simple* getUniquePtrByRelease()
{
    std::unique_ptr<Simple> ptr(new Simple(10));
    ptr->info_extend = "unique_ptr";
    return ptr.release();
}

void deleteGetsharePtr()
{
    Simple* simple = new Simple(10);
    simple->info_extend = "deleteGetsharePtr";
    boost::shared_ptr<Simple> ptr(simple);

    delete ptr.get();

    simple->PrintSomething();
}

void TestSmartPointConcrete()
{
    SmartPoint<Simple> cp1(new Simple(99));
    cp1.referenceCount();
    cp1->info_extend = "TestSmartPointConcrete";
    cp1->PrintSomething();

    SmartPoint<Simple> cp2(cp1);
    cp2.referenceCount();
    SmartPoint<Simple> cp3;

    cp3 = cp2;
    cp3.referenceCount();
    cp3 = cp1;
}

enum VUIImplPtrKey
{
    VUI_MEDIAIMPL_KEY,
    VUI_IMPL_KEY_MAX
};
typedef std::shared_ptr<Simple> VUIImplSmartPtr;
typedef std::map<VUIImplPtrKey, VUIImplSmartPtr> VUIImplPtrMap;

class ptrTest1
{
public:
    ptrTest1()
    {

    }

    ~ptrTest1()
    {
        TCLOGD("ptrTest1 destory");
    }


    VUIImplSmartPtr getFCImplPtr(VUIImplPtrKey key)
    {
        VUIImplPtrMap::const_iterator iter = m_vuiImpPtrMap.find(key);

        if (m_vuiImpPtrMap.end() != iter && iter->second != nullptr) {
            return iter->second;
        }

        TCLOGD("return ptr is null");
        return nullptr;
    }

    void initializeAllImpl()
    {
        VUIImplSmartPtr vui = VUIImplSmartPtr(new Simple(10));
        vui->info_extend = "share_ptr";
        m_vuiImpPtrMap.insert(std::make_pair(VUI_MEDIAIMPL_KEY, vui));
    }

private:
    VUIImplPtrMap m_vuiImpPtrMap;
};

int main() {
    TC_Log::setLogStatus(true);
//    boost::shared_ptr<Simple> ptr(new Simple(10));

    ptrTest1 lll;

    lll.initializeAllImpl();
    Simple* ll = lll.getFCImplPtr(VUI_MEDIAIMPL_KEY).get();
    ll->PrintSomething();
    ll = nullptr;

    switch (11) {
    case 1:
        sharePtrTest();
        break;
    case 2:
        // The share_ptr of life cycle is within the function
        getSimplePtr()->PrintSomething();
        break;
    case 3:
        // The share_ptr of life cycle is outside the function
//        ptr->info_extend = "share_ptr";
//        getSimplePtr1(ptr)->PrintSomething();
        break;
    case 4:
        // return Simple Object
        getSimpleObject().PrintSomething();
        break;
    case 5:
        // The scope of use of the boost::share_ptr
        sharePtrRange();
        break;
    case 6:
        // The description of the use of release
        Simple* uniquePtr;
        uniquePtr = getUniquePtrByRelease();
        uniquePtr->PrintSomething();
        delete uniquePtr;
        uniquePtr = nullptr;
        break;
    case 7:
        deleteGetsharePtr();
        break;
    case 8:
        TestSmartPointConcrete();
        break;
    case 9:
        // memory leak
        CirculationError();
        break;
    case 10:
        WeakPointSolveCirculationError();
        break;
    case 11:
//        getSimpleSmartPtr()->PrintSomething();
        break;
    default:
        printf("undefine!\n");
        break;
    }
}
