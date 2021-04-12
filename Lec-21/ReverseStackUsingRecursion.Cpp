
#include <iostream>
#include <stack>   ///include header file for stack
using namespace std;


///insert a new value at the bottom of the stack,keeping rest of
///the value in same order
void insertAtBottom(stack<int>&s,int val){
    ///base case: if already empty then insert the value as it will be at bottom
    if(s.empty()){
        s.push(val);
        return;

    }

    ///remove elements so that you can come closer to an empty stack
    int x=s.top();
    s.pop();
    insertAtBottom(s,val);

    ///re-insert top value as we want all  the  previous elements
    s.push(x);
}


void reverse(stack<int> &s){
    //base case: if already empty then it is already reversed
    if(s.empty())
        return;

    //take the first element and it is at bottom
    int x=s.top();
    s.pop();

    ///reverse everything except the first element
    reverse(s);

    ///finally insert the top element at last
    insertAtBottom(s,x);


}

int main(){


    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverse(s);
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    //cout << s.size() << endl;



}


