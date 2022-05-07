
#ifndef MYSTACK_H
#define MYSTACK_H

#include "double_linked_list.h"

using namespace std;

class Stack {

private:

    // List as linked list
    DoubleLinkedList linkedList;
public:

    // Check if list is empty or not
    bool empty() const;

    // Push in back of list
    void push(int const &);

    // Pop of back of list
    int pop();

};

bool Stack::empty() const {
    return linkedList.empty();
};

void Stack::push(int const &value) {
    linkedList.pushBack(value);
};

int Stack::pop() {

    int back = linkedList.back();
    linkedList.popBack();
    return back;
};


#endif
