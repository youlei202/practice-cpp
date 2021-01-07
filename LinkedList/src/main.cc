#include <iostream>
#include "linkedlist.h"
#include "linkedlist.cc"

int main(void) {

    LinkedList<int> l;
    std::cout << "size: " << l.Size() << std::endl;
    l.Append(4);
    l.Append(5);
    l.Insert(0,1);
    l.Insert(0,2);
    l.Insert(1,3);
    std::cout << "size: " << l.Size() << std::endl;
    l.Display();
    l.Erase(1);
    l.Display();
    l.Erase(1);
    l.Display();
    std::cout << "size: " << l.Size() << std::endl;
    l.Erase(0);
    l.Display();
    std::cout << "size: " << l.Size() << std::endl;

    l.Insert(0,1);
    l.Insert(0,2);
    l.Insert(0,3);
    l.Display();
    std::cout << "size: " << l.Size() << std::endl;
    l.Swap(0,2);
    l.Display();
    std::cout << "size: " << l.Size() << std::endl;

    l.Append(6);
    l.Append(7);
    l.Display();
    return 0;
}