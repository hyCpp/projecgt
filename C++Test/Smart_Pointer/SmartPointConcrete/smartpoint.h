#ifndef SMARTPOINT
#define SMARTPOINT
#include <stdio.h>

template<typename T>
class SmartPoint
{
public:
    //default construct
    SmartPoint(T * p = nullptr)
        : _ptr(p)
        , _reference_count(new size_t)
    {
        if (!p) {
            *_reference_count = 0;
        }
        else {
            *_reference_count = 1;
        }
    }

    //copy construct
    SmartPoint(const SmartPoint& sp)
    {
        if (this != &sp) {
            _ptr = sp._ptr;
            _reference_count = sp._reference_count;
            (*_reference_count)++;
        }
    }

    //overload
    SmartPoint& operator = (const SmartPoint& sp)
    {
        if (sp._ptr == _ptr) {
            return *this;
        }

        if (_ptr){
            (*_reference_count)--;
            if ((*_reference_count) == 0) {
                delete _ptr;
                _ptr = nullptr;
                delete _reference_count;
            }
        }

        _ptr = sp._ptr;
        _reference_count = sp._reference_count;
        (*_reference_count)++;
        return *this;
    }

    T& operator *()
    {
        if (_ptr) {
            return *_ptr;
        }
    }

    T* operator ->()
    {
        return _ptr;
    }

    ~SmartPoint()
    {
        if (--(*_reference_count) == 0) {
            delete _ptr;
            _ptr = nullptr;
            delete _reference_count;
            printf("destory ok\n");
        }
    }

    void  referenceCount()
    {
        printf("reference = %d\n", *_reference_count);
    }

private:
    T* _ptr;
    size_t* _reference_count;
};

#endif // SMARTPOINT

