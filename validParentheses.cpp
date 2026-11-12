#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool isValid(string s) {
    stack<char> myStack;

    for (int i = 0; i < s.size(); i++) {

        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            myStack.push(s[i]);
        }

        else if (s[i] == '}' || s[i] == ']' || s[i] == ')') {

            if (myStack.empty()) {
                return false;
            }

            char top = myStack.top();

            if ((s[i] == '}' && top == '{') ||
                (s[i] == ']' && top == '[') ||
                (s[i] == ')' && top == '(')) {

                myStack.pop();
            } 
            else {
                return false;
            }
        }
    }

    return myStack.empty();
}
