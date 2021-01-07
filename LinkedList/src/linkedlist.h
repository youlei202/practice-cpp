#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<class T>
struct ListNode {
    ListNode(T value): data(value), next(nullptr) {}
    T data;
    ListNode<T>* next;
};

template<class T>
class LinkedList {
    public:
    LinkedList();
    ~LinkedList();

    int Size(){ return this->size; }

    void Insert(int index, T data);
    void Append(T data);
    void Erase(int index);
    void Display();
    void Swap(int index_1, int index_2);

    private:
    ListNode<T>* head;
    ListNode<T>* tail;
    int size;
};

#endif