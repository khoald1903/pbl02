#include "Linkedlist.h"

int main()
{
    Linkedlist<int> x;
    struct node<int> *a = new struct node<int>;
    a->t = 5;
    struct node<int> *b = new struct node<int>;
    b->t = 10;
    x.add(a);
    x.add(b);
    x.show();
    return 0;
}

