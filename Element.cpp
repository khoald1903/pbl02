#include "Element.h"
template <class T>
Element<T>::Element()
{
    p_head = NULL;
}

template <class T>
void Element<T>::AddIndex(int k, T t)
{
    NodeData<T> *node = new NodeData<T>;
    node->SetData(t);
    NodeData<T> *before, *after;
    after = p_head;
    int n = 0;
    while (after != NULL)
    {
        if (n != k)
        {
            before = after;
            after = after->GetPnext();
            n++;
        }
        else
            break;
    }
    node->SetPnext(after);
    if (p_head == after)
    {
        p_head = node;
    }
    else
        before->SetPnext(node);
}

template <class T>
int Element<T>::GetSize()
{
    NodeData<T> *p;
    p = p_head;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->GetPnext();
    }
    return count;
}

template <class T>
void Element<T>::DeleteIndex(int k)
{
    NodeData<T> *before, *after;
    after = p_head;
    int n = 0;
    while (after != NULL && (n != k))
    {
        before = after;
        after = after->GetPnext();
        n++;
    }
    if (after != NULL)
    {
        if(p_head == after)
        {
            delete after;
          //  delete p_head;
            p_head = NULL;
        }
        else
        {
            before->SetPnext(after->GetPnext());
        }
        delete after;
    }
}

template <class T>
T Element<T>::GetIndex(int index)
{
    NodeData<T> *p;
    p = p_head;
    int count = 0, size = this->GetSize();

    while (p != NULL && count++ != index)
    {
        p = p->GetPnext();
    }
    return p->GetData();
}
template <class T>
void Element<T>::Show()
{
    NodeData<T> *p;
    p = p_head;
    int count = 0, size = this->GetSize();

    while (p != NULL && count++ != size)
    {
        cout << p->GetData();
        p = p->GetPnext();
    }
}
template <class T>
void Element<T>::Add(T t)
{
    AddIndex(GetSize(), t);
}

template <class T>
NodeData<T> *Element<T>::GetPhead()
{
    return p_head;
}

template <class T>
void Element<T>::SetPhead(NodeData<T> *temp)
{
    p_head = temp;
}
//  template class Element<int>;
// template class Element<Product>;
// template class NodeData<Customers>;
// template class NodeData<admin>;
