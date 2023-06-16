/*
FILE: wk8_stacks_linkedList_Josue.cpp

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

#include "node2.h"
#include "stack2.h"
#include <iostream> // cout, endl
#include <vector> // vector

using namespace main_savitch_7B; // stack class
using namespace main_savitch_6B; // node class
using std::vector;
using std::endl;
using std::cout;

template<class T>
void showBottomToTop(stack<T>& s1);

template<class T>
bool compareStacks(stack<T>& s1, stack<T>& s2);

int main(){
    stack<int> s1;
    stack<int> s2;

    s2.push(10);
    s2.push(20);
    s2.push(30);

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << "s1: ";
    showBottomToTop(s1);

    cout << "s2: ";
    showBottomToTop(s2);
    cout << endl;
    
    compareStacks(s1, s2) ? cout << "same" : cout << "not the same";
    cout << endl << endl;

    cout << "s1: ";
    showBottomToTop(s1);

    cout << "s2: ";
    showBottomToTop(s2);

    return 0;
}

template<class T>
void showBottomToTop(stack<T>& s1){
    if(s1.empty() == true)
        return;

    vector<T> vec;
    vec.reserve(s1.size());

    while(s1.empty() == false){
        vec.push_back(s1.top());
        s1.pop();
    }

    for(auto it = vec.end() - 1; it >= vec.begin(); it--){
        cout << *it << " ";
        s1.push(*it);
    }

    cout << endl;
    return;
}

template<class T>
bool compareStacks(stack<T>& s1, stack<T>& s2){
    if(s1.size() != s2.size())
        return false;

    bool check{true};
    vector<T> vec1;
    vector<T> vec2;
    vec1.reserve(s1.size());
    vec2.reserve(s2.size());

    // only will get here if both are same size
    while(s1.empty() == false){
        if(s1.top() != s2.top()){
            check = false;
            break;
        }
        vec1.push_back(s1.top());
        vec2.push_back(s2.top());
        s1.pop();
        s2.pop();
    }

    auto it1 = vec1.end() - 1;
    auto it2 = vec2.end() - 1;
    
    // restores both to original state if necessary
    for(it1; it1 >= vec1.begin(); it1--){
        s1.push(*it1);
        s2.push(*it2);
        it2--;
    }

    return check;
}
