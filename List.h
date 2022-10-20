#include <iostream>
#include "admin.cpp"
using namespace std;


template <class T> class List
{
    private:
        T *F; 
        int realsize;
        int size;
    public:
        List();
        void Add(T t);
        T Getindex(int i);
        int Getsize();
        void Delete(int index);
        ~List();
};