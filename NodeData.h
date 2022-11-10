#include <iostream>
#include <string>


using namespace std;

template <class T>
class NodeData
{
private:
    NodeData<T> *pnext;
    T data;

public:
    NodeData();
    ~NodeData();
    T GetData();
    void SetData(T node);
    NodeData<T> *GetPnext();
    void SetPnext(NodeData<T> *next);
};

