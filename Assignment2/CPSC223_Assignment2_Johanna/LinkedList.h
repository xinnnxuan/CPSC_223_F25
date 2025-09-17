#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>

template <typename T>
class LinkedList
{
public:
    // default constructor
    // set head to nullptr
    LinkedList();

    // destructor
    // delete all nodes in the list from memory
    ~LinkedList();

    // adds a new node with data value at beginning of list
    void insert(const T &data);

    // finds and removes the first occurance of data value from list
    void remove(const T &data);

    // searches the list for the data value
    // if found, search returns true, else returns false
    bool search(const T &data) const;

    // prints the list to the terminal
    void display() const;

    // checks if list is empty
    // returns true if list is empty, else false
    bool isEmpty() const;

private:
    Node<T> *head;
};

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template <typename T>
void LinkedList<T>::display() const
{
    Node<T> *current = head;
    if (current != nullptr)
    {
        std::cout << "#";
    }
    while (current != nullptr)
    {
        std::cout << current->getData() << " ";
        current = current->getNext();
    }
    std::cout << "#" << std::endl;
}

// you finish remaining functions
template <typename T>
LinkedList<T>::~LinkedList()
{
    // Delete all nodes to prevent memory leaks
    Node<T> *current = head;
    while (current != nullptr)
    {
        Node<T> *next = current->getNext();
        delete current;
        current = next;
    }
}

template <typename T>
void LinkedList<T>::insert(const T &data)
{
    // Create a new node with the given data
    Node<T> *newNode = new Node<T>(data);
    // Set the new node's next to current head
    newNode->setNext(head);
    // Update head to point to the new node
    head = newNode;
}

template <typename T>
void LinkedList<T>::remove(const T &data)
{
    // Handle empty list case
    if (head == nullptr)
    {
        return;
    }

    // Handle case where head node contains the data to remove
    if (head->getData() == data)
    {
        Node<T> *temp = head;
        head = head->getNext();
        delete temp;
        return;
    }

    // Find the node to remove
    Node<T> *current = head;
    while (current->getNext() != nullptr)
    {
        if (current->getNext()->getData() == data)
        {
            Node<T> *temp = current->getNext();
            current->setNext(current->getNext()->getNext());
            delete temp;
            return;
        }
        current = current->getNext();
    }
}

template <typename T>
bool LinkedList<T>::search(const T &data) const
{
    // Find the data
    Node<T> *current = head;
    while (current != nullptr)
    {
        if (current->getData() == data)
        {
            return true;
        }
        current = current->getNext();
    }
    return false;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return head == nullptr;
}

#endif
