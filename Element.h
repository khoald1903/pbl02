#include "NodeData.cpp"

template <class T>
class Element
{
protected:
    NodeData<T> *p_head;

public:
    Element();
    void AddIndex(int index, T t);
    void Add(T t);
    void DeleteIndex(int ID);
    int GetSize();
    T GetIndex(int index);
    void Show();

    NodeData<T> *GetPhead();
    void SetPhead(NodeData<T> *temp);
};
