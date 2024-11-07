// day la file node.cpp chua class Node
#ifndef NODE
#define NODE

template <class T>
class Node
{
private:
    T data;
    Node<T> *next;
    Node<T> *prev;

public:
    Node()
    {
        next = NULL;
        prev = NULL;
    }

    Node(T _data)
    {
        this->data = _data;
        next = NULL;
        prev = NULL;
    }

    Node(T _data, Node<T> *_prev, Node<T> *_next)
    {
        this->data = _data;
        this->prev = _prev;
        this->next = _next;
    }

    Node<T> *getNext()
    {
        return next;
    }

    Node<T> *getPrev()
    {
        return prev;
    }

    T &getData()
    {
        return data;
    }

    void setNext(Node<T> *_next)
    {
        this->next = _next;
    }

    void setPrev(Node<T> *_prev)
    {
        this->prev = _prev;
    }

    void setData(T _data)
    {
        this->data = _data;
    }
};

#endif