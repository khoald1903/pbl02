#include "Element.h"
template <class T> Element<T>::Element()
{
    realsize = 100;
    size = 0;
    F = new T[realsize];
}

template <class T> Element<T>::~Element()
{
    delete[] this->F;
}

template <class T> void Element<T>::Add(T t)
{
    if(size == realsize)
    {
        realsize +=1000;
        T *temp = new T[realsize];
        for(int i = 0; i < size; i++)
        {
            *(temp+i) = *(F+i);
        }
        delete[] F;
        F = temp;
        temp = new T;
        delete temp;
    }

    *(F+size) = t;
    size++;
}


template <class T> int Element<T> ::Getsize()
{
    return size;
}


template <class T>
T Element<T> ::Getindex(int i)
{
    return *(F+i);
}

template <class T> void Element<T> ::Delete(int index)
{
    for(int i = index; i < size - 1; i++)
    {
        *(F+i) = *(F+i+1);
    }
    size--;
}

template class Element<int>;
template class Element<admin>;
template class Element<Staff>;
