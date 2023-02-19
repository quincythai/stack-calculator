#include <iostream>
#include "ArrayStack.h"

using namespace std;

int main()
{
    // 5 6 + 7 *
    // alternative to (5 + 6) * 7

    //here is the stack at each step
    /*
    5
    5 6
    --
    11
    11 7
    --
    77
    --> result is at top of the stack


    5 6 7 * + alternative to 5 + (6 * 7)
    5

    5 6

    5 6 7

    5

    5 42


    --
    
    47


    */

    ArrayStack<int> myStack;
    myStack.push(5);
    myStack.push(6);
    myStack.push(7);

    cout << myStack.top() << endl;


}