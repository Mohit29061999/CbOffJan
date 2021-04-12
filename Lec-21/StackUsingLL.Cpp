#include <iostream>
using namespace std;


//linked list data type
class Node{
public:
    int val;

    //to get next node address
    Node* next;

    Node(int v){
        val = v;
        next =NULL;
    }
};


class Stack{
private:
    Node* head;
    int cs;  //to give number of elements in ll

public:
    Stack(){
        head=NULL;
        cs=0;
    }

    ///insert at start of a ll
     void push(int val){
        Node* n = new Node(val);  ///firstly create the new node
        cs++;
        //if it is my first node
         if(head==NULL){
            head=n;
            return;  ///compulsory
         }

         n->next = head;
         head=n;
         return;       ///optional
    }

    ///delete from start
    void pop(){
        if(cs==0)
            return;
        cs--;

        ///if it is the only element
        if(head->next==NULL){
            delete head;
            head=NULL;
            return;
        }

        Node* temp = head;
        head=head->next;
        delete temp;

    }

    int size(){
        return cs;
    }

    bool empty(){
        if(head==NULL)
            return true;
        else
            return false;
    }

    int top(){
        return head->val;
    }

};



int main(){

  Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    cout << s.size() << endl;

}




