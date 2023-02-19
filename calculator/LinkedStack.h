#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <stdexcept>
using namespace std;

template <class T>
class Node
{
    public:
        T value;
        Node<T>* next;
        Node(const T& v = T(), Node<T>* n = nullptr)
        {
            value = v;
            next = n;
        }
};

template <class T>
class LinkedStack
{
    private:
        Node<T>* topPtr;
        int size;
    public:
        LinkedStack()
        {
            topPtr = nullptr;
            size = 0;
        }
        LinkedStack(const LinkedStack &other)
        {
            topPtr = nullptr;
            size = 0;

            if (other.isEmpty())
                return;
            
            topPtr = new Node<T>(other.topPtr->value);
            Node<T>* pre = topPtr;
            Node<T>* otherCurrent = other.topPtr->next;
            while (otherCurrent != nullptr)
            {
                pre->next = new Node<T>(otherCurrent->value);
                otherCurrent = otherCurrent->next;
                pre = pre->next;
            }
            size = other.size();
        }

        ~LinkedStack()
        {
            while (!isEmpty())
                pop();
        }

        bool isEmpty() const
        {
            return top == nullptr;
        }
        bool isFull() const
        {
            return false;
        }
        T& top()
        {
            if (isEmpty())
                throw range_error("Cannot get top of empty stack");
            return topPtr->value;
        }
        void pop()
        {
            if (isEmpty())
                return;
            Node<T>* temp = topPtr;
            topPtr = topPtr->next;
            delete temp;
            size--;
        }
        void push(const T& v)
        {
            topPtr = new Node<T>(v, topPtr);
            size++;
        }
        int getSize() const
        {
            return size;
        }
};


#endif