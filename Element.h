#include <iostream>
//#include "Staff.h"
#include "Customers.h"
#include "admin.h"
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