#include "LinkedStack.h"
#include <iostream>
using namespace std;

int factorial(int n) {
    int result = 1;
    while (n > 1) 
        result *= n--;
    return result;
}
int binaryEval(int b, int c, char op) {
    if (op == '+') return b + c;
    if (op == '-') return b - c;
    if (op == '*') return b * c;
    if (op == '/') return b / c;
    return 0; // unknown op or error
}
int unaryEval(int b, char op) {
    if (op == '!') return factorial(b);
    if (op == '~') return -b;
    return 0;  // unknown op or error
}

// Decide whether ch is a character in charSet.
bool isIn(char ch, char charSet[]) {
    while (*charSet != '\0' && *charSet != ch)
        charSet++;
    return *charSet == ch;
}

// Return true if ch is a digit
bool isDigit(char ch) {
    return '0' <= ch && ch <= '9';
}

// Convert char d to an int.
int toInt(char d) {
    return d - '0';
}

// Update stack based by performing the operation op.
void updateStack(LinkedStack<int> & st, char op) {
    char binaryOps[] = "+-*/", unaryOps[] = "!~";
    int y = st.top(); // an operand
    st.pop();
    if (isIn(op, unaryOps))
        st.push(unaryEval(y, op));
    else if (isIn(op, binaryOps)) {
        int x = st.top(); // the other operand 
        st.pop();
        st.push(binaryEval(x, y, op));
    }
    else 
        cout << "UNKNOWN OPERATOR!" << endl;
}

int main() {
    char tok;
    do {
        LinkedStack<int> stack;
        cout << "Enter a postfix expression followed by . or q to quit: ";
        cin >> tok;
        if (tok != 'q') {
            do {
                if (isDigit(tok))
                    stack.push(toInt(tok)); 
                else updateStack(stack, tok);
                cin >> tok;
            } while (tok != '.');
            cout << "Result = " << stack.top() << '.' << endl;;
        }
    } while (tok != 'q');
    cout << "Bye!" << endl;
    return 0;
}