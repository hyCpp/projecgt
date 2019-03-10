#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include "../../LogConfig/Log_Func.h"
#include "../../LogConfig/Log_Func.cpp"
#include <string>
#include <string.h>
#include <stddef.h>
#include <cstdlib>
#include <climits>
#include <new>

class alloc
{

};

// 测试typename template, 可否再有template
template<typename T, typename Alloc = alloc>
class vector
{
public:
    ~vector(){}
    typedef T value_type;
    typedef value_type* iterator;

    template <typename I>
    void insert(iterator pos, I first, I last) {
        TCLOGD("insert()");
    }
};

inline size_t __deque_buf_size(size_t n, size_t sz)
{
    return n != 0 ? n : (sz < 512 ? size_t(512 / sz) : size_t(1));
}

template<typename T, typename ref, typename ptr, size_t bufSize>
struct __deque_iterator {
    typedef __deque_iterator<T, T&, T*, bufSize> iterator;
    typedef __deque_iterator<T, const T&, const T*, bufSize> const_iterator;
    static size_t buffer_size() {
        return __deque_buf_size(bufSize, sizeof(T));
    }
};

// 测试typename template, 可否有 non-type template参数
template<typename T, typename Alloc = alloc, size_t bufSize = 0>
class deque {
public:
    deque() {
        TCLOGD("deque");
    }

    typedef __deque_iterator<T, T&, T*, bufSize> iterator;
};

// 根据前一个参数T, 设定下一个参数sequence的默认值位deque<T>
template <typename T, typename Sequence = deque<T> >
class stack {
public:
    stack() {
        TCLOGD("stack");
    }

private:
    Sequence c;
};

namespace STL_TEMPLATE_NULL {
#define __STL_TEMPLATE_NULL template<>

template<typename Key>
struct hash {
    void operator() ()
    {
        TCLOGD("hash<T>");
    }
};

__STL_TEMPLATE_NULL struct hash<char> {
    void operator() ()
    {
        TCLOGD("hash<char>");
    }
};

__STL_TEMPLATE_NULL struct hash<unsigned char> {
    void operator() ()
    {
        TCLOGD("hash<unsigned char>");
    }
};

}

namespace temporary_object {
template <typename T>
class printf
{
public:
    void operator () (const T& t)
    {
        std::cout<< t <<std::endl;
    }
};

template<typename InputIter, typename Function>
Function for_each(InputIter beg, InputIter end, Function f) {
    while (beg != end) {
        f(*beg++);
    }
}
}

namespace increment_dereference {
class _int
{
    friend std::ostream& operator << (std::ostream& os, const _int& i);
public:
    _int(int i)
        : m_i(i)
    {

    }
    // prefix: increment and then fetch
    _int& operator ++ ()
    {
        ++(this->m_i);
        return *this;
    }
    //posfix: fetch and then increment
    const _int operator ++ (int) // 该参数不会被调用，区分前缀和后缀
    {
        _int old = *this;
        ++(*this);
        return old;
    }

    // prefix: decrement and then fetch
    _int& operator -- ()
    {
        --(this->m_i);
        return *this;
    }
    //posfix: fetch and then decrement
    const _int operator -- (int)
    {
        _int old = *this;
        --(*this);
        return old;
    }
    int& operator * () const
    {
        return (int&)m_i;
    }


private:
    int m_i;
};

std::ostream& operator << (std::ostream& os, const _int& i)
{
    os << '[' << i.m_i <<']';
    return os;
}
}

namespace _allocate_ {
// 将::operator new and ::operator delete进行封装, 它将对象的空间分配和构造分离开来
template<typename T>
inline T* _allocate(ptrdiff_t size, T*)
{
    std::set_new_handler(0);
    T* tmp = (T*)(::operator new((size_t)(size * sizeof(T))));
    if (tmp == 0) {
        std::cerr<< "out of memory" <<std::endl;
        exit(1);
    }
    return tmp;
}

template<typename T>
inline void _deallocate(T* buf)
{
    ::operator delete(buf);
}

template<typename T1, typename T2>
inline void _construct(T1* p, const T2& value)
{
    new (p) T1(value);
}

template<typename T>
inline void _destroy(T* ptr)
{
    ptr->~T();
}
template<typename T>
class allocator
{
public:
    typedef T               value_type;
    typedef T*              pointer;
    typedef const T*        const_pointer;
    typedef T&              reference;
    typedef const T&        const_reference;
    typedef size_t          size_type;
    typedef ptrdiff_t       difference_type;

    template <typename U>
    struct rebind {
        typedef allocator<U> other;
    };

    pointer allocate(size_type n, const void* hint = 0)
    {
        return _allocate((difference_type)n, (pointer)0);
    }
    void deallocate(pointer p, size_type n)
    {
        _deallocate(p);
    }
    void construct(pointer p, const T& value)
    {
        _construct(p, value);
    }
    void destroy(pointer p)
    {
        _destroy(p);
    }
    pointer address(reference x)
    {
        return (pointer)&x;
    }
    const_pointer const_address(const_reference x)
    {
        return (const_pointer)&x;
    }
    size_type max_size() const
    {
        return size_type(UINT_MAX/sizeof(T));
    }
};
}

int main()
{
    TC_Log::setLogStatus(true);
    int arr[5] = {17, 12, 31, 2, 9};
    unsigned int ni;

// ---------------------------------------
    vector<int> x;
    vector<int>::iterator iter;
    x.insert(iter, arr, arr + 5);
// ---------------------------------------
    stack<int> x1;
// ---------------------------------------
    LOGD("size = [%d]", deque<int>::iterator::buffer_size());
    LOGD("size = [%d]", deque<int, alloc, 64>::iterator::buffer_size());
// ---------------------------------------
    STL_TEMPLATE_NULL::hash<long> hash1;
    STL_TEMPLATE_NULL::hash<char> hash2;
    STL_TEMPLATE_NULL::hash<unsigned char> hash3;
    hash1();
    hash2();
    hash3();
// ---------------------------------------
    std::vector<int> iv(arr, arr + 5);
    temporary_object::for_each(iv.begin(), iv.end(), temporary_object::printf<int>());
// ---------------------------------------
    increment_dereference::_int _i(18);
    LOGD("_i = %d", _i++);
    LOGD("_i = %d", ++_i);
    LOGD("_i = %d", _i--);
    LOGD("_i = %d", --_i);
    LOGD("_i = %d", *_i);
// ---------------------------------------
    std::vector<int, _allocate_::allocator<int> > _vec(arr, arr + 5);
    for (int i = 0; i < _vec.size(); ++i) {
        LOGD("%d", _vec[i]);
    }
// ---------------------------------------

}
