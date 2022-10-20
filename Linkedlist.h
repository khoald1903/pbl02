#include <iostream>
using namespace std;

template <class T>
struct node
{
    T t;
    struct node *next;
};

template <class T> class Linkedlist
{
    private:
         struct node<T> *F;

    public:
        Linkedlist();
        void add(struct node<T> *x);
        void Delete(struct node<T> *t);
        void Delete(int index);
        void InsertSort(struct node<T> *x);
        void show();
};
