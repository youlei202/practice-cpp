#include <iostream>
#include "linkedlist.h"

template<class T>
LinkedList<T>::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

template<class T>
LinkedList<T>::~LinkedList() {
    ListNode<T>* current = this->head;
    ListNode<T>* next = nullptr;
    while ( current != nullptr ) {
        next = current->next;
        delete current;
        current = next;
    }
}

template<class T>
void LinkedList<T>::Insert(int index, T data) {
    if ( index< 0 ){
        index = 0;
    }
    
    ListNode<T>* current = this->head;
    ListNode<T>* previous = nullptr;
    int counter = 0;
    while ( counter < index && current != nullptr ) {
        previous = current;
        current = current->next; 
        counter ++;
    }

    ListNode<T>* new_node_ptr = new ListNode<T>(data);

    if ( this->head == nullptr ) {
        this->head = new_node_ptr;
    } else if ( current == nullptr ) {
        previous->next = new_node_ptr;
    } else {
        new_node_ptr->next = current;
        if ( previous == nullptr ) {
            this->head = new_node_ptr;
        } else {
            previous->next = new_node_ptr;
        }
    }
    if ( index >= this->size ) {
        this->tail = new_node_ptr;
    }
    this->size ++;
}

template<class T>
void LinkedList<T>::Erase(int index) {
    if ( index < 0 || index>= this->size ) {
        return;
    } 
    ListNode<T>* current = this->head;
    ListNode<T>* previous = nullptr;
    int counter = 0;
    while ( counter<index ) {
        counter ++;
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        return;
    } else {
        if (previous == nullptr) {
            this->head = current->next;
        } else {
            previous->next = current->next;
        }
        delete current;
        this->size --;
    }

    if ( index==this->size-1 ){
        this->tail = previous;
    }
}

template<class T>
void LinkedList<T>::Display() {
    ListNode<T>* current = this->head;
    while ( current != nullptr ) {
        std::cout << current->data;
        current = current->next;
    }
    std::cout << std::endl;
}

template<class T>
void LinkedList<T>::Swap(int index_1, int index_2) {

    if ( index_1<0 || index_2<0 || index_1>=this->size || index_2>=this->size ) {
        std::cerr << "Swap: index out of range!" << std::endl;
        exit(-1);
    }

    if ( index_1==index_2 ) {
        return;
    }

    ListNode<T>* left_ptr = this->head;
    ListNode<T>* left_prev_ptr = nullptr;
    int left_position = index_1 > index_2? index_2 : index_1;
    for ( int i=0; i<left_position; i++ ) {
        left_prev_ptr = left_ptr;
        left_ptr = left_ptr->next;
    }
    
    ListNode<T>* right_ptr = left_ptr;
    ListNode<T>* right_prev_ptr = left_prev_ptr;

    int right_position = index_1 > index_2? index_1 : index_2;
    for ( int i=left_position; i<right_position; i++ ) {
        right_prev_ptr = right_ptr;
        right_ptr = right_ptr->next;
    }

    
    ListNode<T>* left_ptr_next = left_ptr->next;
    left_ptr->next = right_ptr->next;

    if (left_position + 1 == right_position) {
        right_ptr->next = left_ptr;
    } else {
        right_ptr->next = left_ptr_next;
        right_prev_ptr->next = left_ptr;
    }

    if ( left_prev_ptr != nullptr ) {
        left_prev_ptr->next = right_ptr;
    } else {
        this->head = right_ptr;
    }

    if ( this->tail == right_ptr ) {
        this->tail = left_ptr;
    }
}

template<class T>
void LinkedList<T>::Append(T data) {
    ListNode<T>* new_node_ptr = new ListNode<T>(data);
    if ( this->tail == nullptr ) {
        this->head = new_node_ptr;
    } else {
        this->tail->next = new_node_ptr;
    }
    this->tail = new_node_ptr;
    this->size ++;
}