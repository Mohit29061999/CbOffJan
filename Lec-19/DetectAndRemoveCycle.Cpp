
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

int Length(Node* head){
    int count =0;
    while(head!=NULL){
       count++;
       head=head->next;

    }

    return count;
}

void insertAtStart(Node* &head,int v){
    //to create a new node
    Node* n =new Node(v);

    //if linkedlist is empty
    if(head==NULL){
        head=n;
        return;
    }

    //rest of the cases
    n->next=head; //to create link
    head=n;
    return;
}





void printLL(Node* head){
    while(head!=NULL){
        cout << head->val << " "; //to print current node val
        head=head->next;  //to go to next node

    }
}






Node* getMid(Node* head){
    Node* s=head;
    Node* f=head->next;

    //move slow by 1 and fast by 2
    while(f!=NULL && f->next !=NULL){
        s=s->next;
        f=f->next;
        f=f->next;
    }

    //slow will point to mid
    return s;
}

//to create cycle
void CreateCycle(Node* head){
    //go to last node
    Node* curr=head;
    while(curr->next!=NULL)
        curr=curr->next;

    //place second node after last node
    curr->next = head->next;
}

bool checkCycle(Node* head){
    if(head==NULL || head->next ==NULL)
        return false;

    Node* f=head;
    Node* s=head;
    while(f!=NULL && f->next!=NULL){



        //f will take 2 steps
        f=f->next;
        f=f->next;
        s=s->next;

         if(f==s)
            return true;

    }

    return false;
}

void detectAndRemoveCycle(Node* head){
    if(checkCycle(head)==false)
        return;

    Node* f=head;
    Node* s=head;

    //move fast by 2 and slow by 1 to get meeting point
    while(f!=NULL && f->next!=NULL){
        f=f->next->next;
        s=s->next;
        if(f==s)
            break;
    }


    //move s from head and f from meeting point at same speed
    //also store prev of fast
    //slow and fast will meet at start of cycle and hence prev point to last node
    //make lastnode->next =NULL
    s=head;
    Node* prev =NULL;
    while(f!=s){
        prev =f;
        f=f->next;
        s=s->next;
    }

    //prev will point to last node so make its next NULL
    prev->next =NULL;
}

int main(){
  Node* head=NULL;  //first node ka address

  insertAtStart(head,4);
  insertAtStart(head,3);
   insertAtStart(head,2);
  insertAtStart(head,1);

  CreateCycle(head);
  //cout << checkCycle(head) << endl; //1 means true and 0 means false;
  detectAndRemoveCycle(head);

  printLL(head);



}

