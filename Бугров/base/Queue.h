#pragma once
#include <iostream>
#include <locale>
#include "MaxValues.h"
#include "Ans.h"
template <class T>
class Queue
{
protected:
    T* pMem;
    int Size;
    int begin;//[begin;end)
    int end;//[begin;end)
public:
    //только для тестов, поэтому его проверять нет смысла - всё и так работает :)
    const T& operator[](size_t index) const;
    Queue();
    Queue(const Queue& q);
    ~Queue();
    //-------------------------------------
    int size();
    bool is_full() const;
    bool is_empty() const;
    void push(const T& obj);
    T pop();
    T get() const;
};
template<class T> 
Queue<T>::Queue<T>()
{
    begin = 0;
    end = 0;
    pMem = new T[MaxQueueSize];
    Size = 0;
}
template<class T>
Queue<T>::Queue<T>(const Queue& q)
{
    begin = q.begin;
    end = q.end;
    Size = q.Size;
    pMem = new T[MaxQueueSize];
    for (int i = begin; i < end; i++)
        pMem[i] = q.pMem[i];
}
template <class T>
Queue<T>::~Queue()
{
    delete[] pMem;
}
template <class T>
const T& Queue<T>::operator[](size_t index) const
{
    if (index > Size)
        throw ans::out_of_range;
    return pMem[(index + begin) % MaxQueueSize];
}
//-----------------------------------------------
template<class T>
int Queue<T>::size()
{
    return Size;
}
template<class T>
bool Queue<T>::is_empty() const
{
    return (Size == 0);
}
template<class T>
bool Queue<T>::is_full() const
{
    return (Size >= MaxQueueSize);
}
template<class T>
void Queue<T>::push(const T& obj)
{
    if (is_full())
        throw ans::full;
    pMem[end] = obj;
    end = ++end % MaxQueueSize;
    Size++;
}
template <class T>
T Queue<T>::pop()
{
    if (is_empty())
        throw ans::empty;
    T obj = pMem[begin];
    begin = ++begin % MaxQueueSize;
    Size--;
    return obj;
}
template <class T>
T Queue<T>::get() const
{
    if (is_empty())
        throw ans::empty;
    return pMem[begin];
}