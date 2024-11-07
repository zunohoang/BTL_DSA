
#ifndef DLIST_REVERSE_ITERATOR
#define DLIST_REVERSE_ITERATOR

template <class T>
class DList_Reverse_Iterator
{
    Node<T> *curr;

public:
    DList_Reverse_Iterator(Node<T> *c = 0) { curr = c; }

    Node<T> *getcurr() { return curr; }

    DList_Reverse_Iterator &operator=(DList_Reverse_Iterator<T> it)
    {
        this->curr = it.getcurr();
        return *this;
    }

    bool operator!=(DList_Reverse_Iterator<T> it)
    {
        return curr != it.getcurr();
    }

    T &operator*()
    {
        return curr->getData();
    }

    DList_Reverse_Iterator operator++(int)
    {
        DList_Reverse_Iterator it = curr;
        curr = curr->getPrev();
        return it;
    }

    DList_Reverse_Iterator operator++()
    {
        curr = curr->getPrev();
        return curr;
    }
};

#endif