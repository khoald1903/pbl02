#include "NodeData.h"
template <class T>
NodeData<T>::NodeData()
{
    pnext = NULL;
}
template <class T>
NodeData<T>::~NodeData()
{
    delete pnext;
}

template <class T>
T NodeData<T>::GetData()
{
    return data;
}

template <class T>
void NodeData<T>::SetData(T node)
{
    data = node;
}

template <class T>
NodeData<T> *NodeData<T>::GetPnext()
{
    return pnext;
}

template <class T>
void NodeData<T>::SetPnext(NodeData<T> *next)
{
    this->pnext = next;
}