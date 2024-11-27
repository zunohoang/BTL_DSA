
#ifndef DLIST_ITERATOR
#define DLIST_ITERATOR

#include "Node.h"

template <class T>
class DList_Iterator
{
    Node<T> *curr;

public:
    DList_Iterator(Node<T> *c = 0)
    {
        curr = c;
    }

    Node<T> *getcurr()
    {
        return curr;
    }

    DList_Iterator &operator=(DList_Iterator<T> it)
    {
        this->curr = it.getcurr();
        return *this;
    }

    bool operator!=(DList_Iterator<T> it)
    {
        return curr != it.getcurr();
    }

    T &operator*()
    {
        return curr->getData();
    }

    DList_Iterator operator++(int)
    {
        DList_Iterator it = curr;
        curr = curr->getNext();
        return it;
    }

    DList_Iterator operator++()
    {
        curr = curr->getNext();
        return curr;
    }
};

#endif