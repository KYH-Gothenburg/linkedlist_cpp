#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    Node();
    Node(T _data);
    ~Node();
    T getData();
    void setData(T data);
    Node<T> *getNext();
    void setNext(Node<T> *next);
    Node<T> *getPrev();
    void setPrev(Node<T> *prev);

private:
    T data;
    Node<T> *next;
    Node<T> *prev;
};

template <typename T>
Node<T>::Node() : data({}), next(nullptr), prev(nullptr) {}

template <typename T>
Node<T>::Node(T _data) : data(_data), next(nullptr), prev(nullptr) {}

template <typename T>
Node<T>::~Node()
{
    cout << "Deleting node with data " << data << endl;
}

template <typename T>
T Node<T>::getData()
{
    return data;
}

template <typename T>
void Node<T>::setData(T data)
{
    this->data = data;
}

template <typename T>
Node<T> *Node<T>::getNext()
{
    return next;
}

template <typename T>
void Node<T>::setNext(Node<T> *next)
{
    this->next = next;
}

template <typename T>
Node<T> *Node<T>::getPrev()
{
    return prev;
}

template <typename T>
void Node<T>::setPrev(Node<T> *prev)
{
    this->prev = prev;
}

template <typename T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(const LinkedList<T> &other);
    ~LinkedList();
    LinkedList<T> &operator=(const LinkedList<T> &other);
    T operator[](int index);
    void clear();
    void pushHead(T data);
    void pushTail(T data);
    T popHead();
    T popTail();
    T peekHead();
    T peekTail();
    void print();
    int size();

private:
    Node<T> *head;
    Node<T> *tail;
    int count;
    void copy(const LinkedList<T> &other);
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), count(0) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &other)
{
    copy(other);
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &other)
{
    if (head)
    {
        clear();
    }
    copy(other);

    return *this;
}

template <typename T>
T LinkedList<T>::operator[](int index)
{
    if (!head || index > count - 1)
    {
        return nullptr;
    }
    int pos = 0;
    Node<T> *tempPtr = head;
    while (pos < index)
    {
        tempPtr = tempPtr->getNext();
        pos++;
    }
    return tempPtr->getData();
}

template <typename T>
void LinkedList<T>::pushHead(T data)
{
    Node<T> *newNode = new Node<T>(data);
    if (!head)
    {
        tail = newNode;
    }
    else
    {
        head->setPrev(newNode);
        newNode->setNext(head);
    }
    head = newNode;
    count++;
}

template <typename T>
void LinkedList<T>::pushTail(T data)
{
    Node<T> *newNode = new Node<T>(data);
    if (!tail)
    {
        head = newNode;
    }
    else
    {
        tail->setNext(newNode);
        newNode->setPrev(tail);
    }
    tail = newNode;
    count++;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T> &other)
{
    if (!other.head)
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    else
    {
        Node<T> *tempPtr = other.head;
        while (tempPtr)
        {
            pushTail(tempPtr->getData());
            tempPtr = tempPtr->getNext();
        }
        count = other.count;
    }
}

int main()
{
    LinkedList<int> ll1();
    LinkedList<int> ll2();

    //ll2 = ll1;
    return 0;
}