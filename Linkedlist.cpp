#include "Linkedlist.h"

template <class T> Linkedlist<T>::Linkedlist()
{
    F = NULL;
}

template <class T>
void Linkedlist<T>::add(struct node<T> *x)
{
    if (F == NULL)
    {
        F = x;
        F->next = NULL;
    }
    else
    {
        struct node<T> *before, *after;
        after = F;
        while (after != NULL)
        {
            before = after;
            after = after->next;
        }
        before->next = x;
        x->next = NULL;
    }
}

template <class T> void Linkedlist<T>::show()
{
    struct node<T> *p;
    p = F;
    while (p != NULL)
    {
        cout << p->t << endl;
        p = p->next;
    }
}

template <class T> void Linkedlist<T>::Delete(struct node<T> *t)
{
    struct node<T> *before, *after;
    after = F;
    while (after != NULL && after->t != t->t)
    {
        before = after;
        after = after->next;
    }
    if (after != NULL)
    {
        if (F == t)
            F = t->next;
        else
            before->next = t->next;
        delete t;
    }
}

template <class T>
void Linkedlist<T>::InsertSort(struct node<T> *x)
{
    struct node<T> *before, *after;
    after = F;
    while (after != NULL && after->t < x->t)
    {
        before = after;
        after = after->next;
    }
    x->next = after;
    if (F == after)
        F = x;
    else
    {
        before->next = x;
    }
}

template <class T>
void Linkedlist<T> ::Delete(int index)
{
    struct node<T> *before, *after;
    int d = 0;
    after = F;
    while (after != NULL && d != index)
    {
        before = after;
        after = after->next;
        d++;
    }
    if (after != NULL)
    {
        if (F == NULL)
            F = NULL;
        else
            before->next = after->next;
    }
}

template class Linkedlist<int>;