#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>
#include "exception.h"
#include <algorithm>

class DoubleLinkedList {
public:
    class DoubleNode {
    public:
        /*
         * Constructor
         * Set value of the node, the previous node & the next node pointer
         */
        DoubleNode(int const & = int(), DoubleNode * = nullptr, DoubleNode * = nullptr);

        /*
         * Return value of the node
         */
        int value() const;

        /*
         * Return the pointer of the previous node
         */
        DoubleNode *previous() const;

        /*
         * Return the pointer of the next node
         */
        DoubleNode *next() const;

        /*
         * Store value of the node
         */
        int nodeValue;
        /*
         * Store the pointer of the previous node
         */
        DoubleNode *previousNode;
        /*
         * Store the pointer of the next node
         */
        DoubleNode *nextNode;
    };

    /*
     * Constructor without input parameter
     * Set the list head & the list tail & the list size to the default value
     */
    DoubleLinkedList();

    /*
     * Constructor with input parameter: Double linked list
     * Set the list head & the list tail & the list size to the default value
     * Copy elements of the list to this list
     */
    DoubleLinkedList(DoubleLinkedList const &);

    /*
     * Destructor
     * While the list is not empty destroys any element.
     */
    ~DoubleLinkedList();

    // Accessors

    /*
     * Return size of the list
     */
    int size() const;

    // Check if the list size is zero or not
    bool empty() const;

    /*
     * Return the value at the top of the list. If the list is empty
     * throws an Underflow error.
     */
    int front() const;

    /*
     * Return the value at the end of the list. If the list is empty
     * throws an Underflow error.
     */
    int back() const;

    /*
     * Return the reference of the head of the list
     */
    DoubleNode *begin() const;

    /*
     * Return the reference of the tail of the list
     */
    DoubleNode *end() const;

    /*
     * Return the address of the first node whose value is equal to the value of the input parameter.
     * If the corresponding value is not found, nullptr is returned.
    */
    DoubleNode *find(int const &) const;

    /*
     * Return the s of elements whose value is equal to the value of the input parameter.
     */
    int count(int const &) const;

    // Mutators

    /*
     * Move the input link list to this linked list.
     * Swap the head, tail & size of the lists
     */
    void swap(DoubleLinkedList &);

    /*
     * Create a new node with the value given in the input,
     * Insert it at the beginning of the list.
     * Move the list head to new node
     */
    void pushFront(int const &);

    /*
     * Create a new node with the value given in the input,
     * Insert it at the end of the list.
     * Move the list tail to new node.
     * Increase the list size.
     */
    void pushBack(int const &);

    /*
     * Delete the starting node of the list. If the list is empty
     * throw an Underflow error.
     * Move the list head to next node.
     * Reduce the list size.
     */
    void popFront();

    /*
     * Delete the last node of the list. If the list is empty
     * throw an Underflow error.
     * Move the list tail to previous node.
     * Reduce the list size
     */
    void popBack();

    /*
     * Delete all nodes whose value is equal to the value of the input parameter,
     * Return the s of deleted nodes.
     * Navigate the list, delete corresponding node
     * Link the previous & the next node
     */
    int erase(int const &);

private:
    /*
     *Pointer to the beginning of the list
     */
    DoubleNode *listHead;
    /*
     * Pointer to the end of the list
     */
    DoubleNode *listTail;
    /*
     * Store the size of the list
     */
    int listSize;

    // Friends

    friend std::ostream &operator<<(std::ostream &, DoubleLinkedList const &);
};

/////////////////////////////////////////////////////////////////////////
//                      Public member functions                        //
/////////////////////////////////////////////////////////////////////////

DoubleLinkedList::DoubleLinkedList() :

        listHead(nullptr),
        listTail(nullptr),
        listSize(0) {

}

DoubleLinkedList::DoubleLinkedList(DoubleLinkedList const &list) :

        listHead(nullptr),
        listTail(nullptr),
        listSize(0) {

    DoubleNode *ptr = list.begin();
    while (ptr != nullptr) {

        pushBack(ptr->value());
        ptr = ptr->next();
    }

}

DoubleLinkedList::~DoubleLinkedList() {

    while (!empty()) {

        popFront();
    }
}

int DoubleLinkedList::size() const {

    return listSize;
}

bool DoubleLinkedList::empty() const {

    return listSize == 0;
}

int DoubleLinkedList::front() const {

    if (empty()) {
        throw Underflow();
    }

    return begin()->value();
}

int DoubleLinkedList::back() const {

    if (empty()) {
        throw Underflow();
    }

    return end()->value();
}

DoubleLinkedList::DoubleNode *DoubleLinkedList::begin() const {

    return listHead;
}

DoubleLinkedList::DoubleNode *DoubleLinkedList::end() const {

    return listTail;
}

DoubleLinkedList::DoubleNode *DoubleLinkedList::find(int const &value) const {

    DoubleNode *node = listHead;

    while (node != nullptr) {
        if (node->value() == value) return node;

        node = node->next();
    }

    return nullptr;
}

int DoubleLinkedList::count(int const &value) const {

    int listCount = 0;

    DoubleNode *node = listHead;

    while (node != nullptr) {
        if (node->value() == value) listCount++;

        node = node->next();
    }

    return listCount;
}

void DoubleLinkedList::swap(DoubleLinkedList &list) {

    std::swap(this->listHead, list.listHead);
    std::swap(this->listTail, list.listTail);
    std::swap(this->listSize, list.listSize);

}

void DoubleLinkedList::pushFront(int const &value) {

    // Next node is old head
    auto *newNode = new DoubleNode(value, nullptr, begin());

    if (empty()) {
        // If list is empty the tail & the head are equal
        listTail = newNode;
    } else {
        listHead->previousNode = newNode;
    }

    listHead = newNode;

    listSize++;
}

void DoubleLinkedList::pushBack(int const &value) {

    // Previous node is old tail
    auto *newNode = new DoubleNode(value, end(), nullptr);

    if (empty()) {
        // If list is empty the tail & the head are equal
        listHead = newNode;
    } else {
        listTail->nextNode = newNode;
    }

    listTail = newNode;

    listSize++;

}

void DoubleLinkedList::popFront() {

    if (!empty()) {

        listSize--;

        DoubleNode *temp = begin();
        listHead = begin()->next();

        // If the list is empty the listHead will be NULL so it has not previous node then the listTail is NULL too
        if (!empty())
            listHead->previousNode = nullptr;
        else
            listTail = nullptr;

        delete temp;

    } else throw Underflow();

}

void DoubleLinkedList::popBack() {

    if (!empty()) {

        listSize--;

        DoubleNode *temp = end();
        listTail = end()->previous();

        // If the list is empty the listTail will be NULL so it has not next node then the listHead is NULL too
        if (!empty())
            listTail->nextNode = nullptr;
        else
            listHead = nullptr;

        delete temp;

    } else throw Underflow();

}

int DoubleLinkedList::erase(int const &value) {

    int number = 0;

    DoubleNode *node = listHead;

    while (node != nullptr) {

        if (node->value() == value) {

            DoubleNode *temp = node;

            // If node is the head, It must move to next node
            if (node != begin())
                node->previous()->nextNode = node->next();
            else
                listHead = node->next();

            // If node is the tail, It must move to previous node
            if (node != end())
                node->next()->previousNode = node->previous();
            else
                listTail = node->previous();

            delete temp;

            listSize--;
            number++;
        }

        node = node->next();
    }

    return number;
}

DoubleLinkedList::DoubleNode::DoubleNode(
        int const &nv,
        DoubleLinkedList::DoubleNode *pn,
        DoubleLinkedList::DoubleNode *nn) :

        nodeValue(nv),
        previousNode(pn),
        nextNode(nn) {

}

int DoubleLinkedList::DoubleNode::value() const {

    return nodeValue;
}

DoubleLinkedList::DoubleNode *DoubleLinkedList::DoubleNode::previous() const {

    return previousNode;
}

DoubleLinkedList::DoubleNode *DoubleLinkedList::DoubleNode::next() const {

    return nextNode;
}

/////////////////////////////////////////////////////////////////////////
//                      Private member functions                       //
/////////////////////////////////////////////////////////////////////////

// If you author any additional private member functions, include them here

/////////////////////////////////////////////////////////////////////////
//                               Friends                               //
/////////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &out, DoubleLinkedList const &list) {
    out << "head";

    // print list from start to end
    for (auto *ptr = list.begin(); ptr != nullptr; ptr = ptr->next()) {
        out << "->" << ptr->value();
    }
    out << "->0" << std::endl << "tail";

    // print list from end to start
    for (DoubleLinkedList::DoubleNode *ptr = list.end(); ptr != nullptr; ptr = ptr->previous()) {
        out << "->" << ptr->value();
    }
    out << "->0";

    return out;
}

#endif