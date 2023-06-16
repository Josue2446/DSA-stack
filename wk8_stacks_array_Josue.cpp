/*
FILE: wk8_stacks_array_Josue.cpp

Summary: Driver file to test functions with stack class

Test Cases: compared two stack objects, one time they were both
            equal, the other time they were different in terms of
            values and size. Boolean output is correct.

Author: Josue 

Date: 05/29/2023

Summary of modifications: N/A

Compiler: Ubuntu (g++)

FUNCTIONS:

    template<class T>
    void showBottomToTop(stack<T>& s1):
        precondition: stack object exist
        postcondition: prints content of stack object from the bottom
                       of the stack to the top. Stack remains unchanged.

    template<class T>
    bool compareStacks(stack<T>& s1, stack<T>& s2):
        precondition: two stack objects exist.
        postcondition: returns a value of type boolean based off if the
                       two stacks passed in are the same or different. Two
                       stacks are said to be the same of they are exactly
                       identical in terms of size and position of values.
                       Both stacks remain unchanged in the end.
*/

#include "stack1.h" // header file
#include <iostream> // cout, endl

using std::cout;
using std::endl;
using namespace main_savitch_7A;

template<class T>
void showBottomToTop(stack<T>& s1);

template<class T>
bool compareStacks(stack<T>& s1, stack<T>& s2);

int main(){
    stack<char> s1;
    stack<char> s2;

    s1.push('h');
    s1.push('e');
    s1.push('l');
    s1.push('l');
    s1.push('o');

    s2.push('h');
    s2.push('e');
    s2.push('l');
    s2.push('z');
    s2.push('o');

    cout << "s1: ";
    showBottomToTop(s1);
    compareStacks(s1, s2) ? cout << "same" : cout << "not the same";
    cout << endl;

    cout << "s1: ";
    showBottomToTop(s1);
    cout << "s2: ";
    showBottomToTop(s2);
    cout << endl;

    return 0;
}

template<class T>
void showBottomToTop(stack<T>& s1){
    if(s1.size() == 0)
        return;

    stack<T> s2;
    
    const int len = s1.size();
    for(int i = 0; i < len; i++){
        s2.push(s1.top());
        s1.pop();
    }
    
    const int len2 = s2.size();
    for(int i = 0; i < len2; i++){
        cout << s2.top() << " ";
        s1.push(s2.top());
        s2.pop();
    }
    
    cout << endl;
    return;
}

template<class T>
bool compareStacks(stack<T>& s1, stack<T>& s2){
    if(s1.size() != s2.size())
        return false;

    const int len = s1.size();
    stack<T> s11;
    stack<T> s22;    
    bool check{true};

    for(int i = 0; i < len; i++){
        if(s1.top() != s2.top()){
            check = false;
            break;
        }
        s11.push(s1.top());
        s1.pop();
        s22.push(s2.top());
        s2.pop();
    }
    
    // restores both stacks passed in by ref to their original
    // state if necessary    
    for(int i = s1.size(); i < len; i++){
        s1.push(s11.top());
        s2.push(s22.top());
        s11.pop();
        s22.pop();
    }

    return check;
}
