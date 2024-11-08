
#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

template <class T>
class Doubly_Linked_List
{
private:
    Node<T> *head;
    Node<T> *trail;
    int n;

public:
    typedef DList_Iterator<T> iterator;
    typedef DList_Reverse_Iterator<T> reverse_iterator;
    iterator begin() { return head; }
    iterator end() { return nullptr; }
    reverse_iterator rbegin() { return trail; }
    reverse_iterator rend() { return nullptr; }

    Doubly_Linked_List()
    {
        head = NULL;
        trail = NULL;
        n = 0;
    }

    Doubly_Linked_List(int len, T element)
    {
        n = 0;
        head = trail = 0;
        while (len--)
            push_back(element);
    }

    int size()
    {
        return n;
    }

    bool empty()
    {
        return n == 0;
    }
    void push_front(T element)
    {
        if (n == 0)
            head = trail = new Node<T>(element);
        else
        {
            head->setPrev(new Node<T>(element, nullptr, head));
            head = head->getPrev();
        }
        n++;
    }

    void push_back(T element)
    {
        if (n == 0)
            head = trail = new Node<T>(element);
        else
        {
            trail->setNext(new Node<T>(element, trail, nullptr));
            trail = trail->getNext();
        }
        n++;
    }

    T &front()
    {
        return head->getData();
    }

    T &back()
    {
        return trail->getData();
    }

    void pop_back()
    {
        if (n == 0)
            return;
        if (n == 1)
        {
            delete trail;
            head = trail = nullptr;
        }
        else
        {
            Node<T> *temp = trail;
            trail = trail->getPrev();
            trail->setNext(nullptr);
            delete temp;
        }
        n--;
    }

    void pop_front()
    {
        if (n == 0)
            return;
        if (n == 1)
        {
            delete head;
            head = trail = nullptr;
        }
        else
        {
            Node<T> *temp = head;
            head = head->getNext();
            head->setPrev(nullptr);
            delete temp;
        }
        n--;
    }

    // chèn vào sau nút p
    void insert(Node<T> *p, T element)
    {
        if (p == nullptr)
            return;
        if (p == trail)
        {
            push_back(element);
            return;
        }
        auto *q = new Node<T>(element, p, p->getNext());
        p->getNext()->setPrev(q);
        p->setNext(q);
        n++;
    }

    // xoa nut p
    void erase(Node<T> *p)
    {
        if (p == nullptr)
            return;
        if (p == head)
        {
            pop_front();
            return;
        }
        if (p == trail)
        {
            pop_back();
            return;
        }
        p->getPrev()->setNext(p->getNext());
        p->getNext()->setPrev(p->getPrev());
        delete p;
        n--;
    }

    // sap xep co cmp
    /*
     *  cach dung
         students.sort([](Student a, Student b){
                return a.getAge() < b.getAge();
         });
     */
    void sort(bool (*cmp)(T, T))
    {
        for (auto i = head; i != nullptr; i = i->getNext())
        {
            for (auto j = i->getNext(); j != nullptr; j = j->getNext())
            {
                if (cmp(i->getData(), j->getData()))
                {
                    // swap(i->getData(), j->getData());
                    T temp = i->getData();
                    i->setData(j->getData());
                    j->setData(temp);
                }
            }
        }
    }
};

#endif // PROBLEM_B_Doubly_Linked_List_H