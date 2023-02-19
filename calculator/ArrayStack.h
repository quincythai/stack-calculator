#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <stdexcept>
using namespace std;

template <class T>
class ArrayStack
{
    public:
        static const int MAXSIZE = 100;
    private:
        T values[MAXSIZE];
        int topIndex;
    public:
        ArrayStack()
        {
            topIndex = -1;
        }
        bool isEmpty() const
        {
            return topIndex == -1;
        }
        bool isFull() const
        {
            return topIndex == MAXSIZE - 1;
        }
        void pop()
        {
            if (topIndex == -1)
                return;
            topIndex--;
        }
        T& top()
        {
            if (topIndex == -1)
                throw range_error("Can't get top of empty stack");
            return values[topIndex];
        }
        bool isFull() const
        {
            return topIndex + 1 == MAXSIZE;
        }
        void push(const T& value)
        {
            if (topIndex + 1 == MAXSIZE)
                return;
            topIndex++;
            values[topIndex] = value;
        }
        bool getSize() const
        {
            return topIndex + 1; //+1 because intiially starts at -1
        }

};

#endif