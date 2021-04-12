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

class Queue{
private:
    Node* head;
    Node* tail;
    int cs;

public:
    Queue(){
        head=NULL;
        tail=NULL;
        cs=0;
    }

    ///insert at end with tail
    void push(int val){
        Node* n = new Node(val);
        cs++;
        ///if it is first element
        if(head==NULL){
            head=tail=n;
            return;
        }

        tail->next = n;
        tail = n;
    }

    ///delete from start
    void pop(){
        if(cs==0)
            return;
        cs--;
        if(head->next==NULL){
                delete head;
            head=tail=NULL;
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
        return head==NULL;
    }

    int front(){
        return head->val;
    }
};





int main(){

  Queue q;
  q.push(4);
  q.push(3);
  q.push(2);
  q.push(1);

  while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
  }

}





