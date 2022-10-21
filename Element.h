#include <iostream>
#include "admin.cpp"
using namespace std;

template <class T>
class Element
{

    T *F;
    int realsize;
    int size;

public:
    Element();
    void Add(T t);
    T Getindex(int i);
    int Getsize();
    void Delete(int index);
    ~Element();
};