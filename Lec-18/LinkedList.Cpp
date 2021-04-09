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

//insertAtEnd
void insertAtEnd(Node* &head,/*Node* &tail,*/int v){
     Node* n =new Node(v);

    //if linkedlist is empty
    if(head==NULL){
        head=/*tail = */n;
        return;
    }

    //to go to last node
    Node* curr=head;
    while(curr->next!=NULL){
        //move one step ahead
        curr=curr->next;
    }

    //tail->next=n;
   // tail = n;
}

void insertAtAnyPos(Node* &head,int v,int pos){
     Node* n =new Node(v);

    //if insert at head
    if(pos==0){
        insertAtStart(head,v);
        return;
    }

    //if insert at end
    if(pos>=Length(head)-1){
        insertAtEnd(head,v);
        return;
    }

    Node* curr=head;
    for(int i=1;i<=pos-1;i++)
        curr=curr->next;

    Node* temp =curr->next;
    curr->next = n;
    n->next = temp;


}



void printLL(Node* head){
    while(head!=NULL){
        cout << head->val << " "; //to print current node val
        head=head->next;  //to go to next node

    }
}

//to search for a value in LL
Node* searchLL(Node* head,int key){
    while(head!=NULL){
        //cout << head->val << " "; //to print current node val
        if(head->val==key)
            return head;
        head=head->next;  //to go to next node

    }

    return NULL;
}


void deleteFromStart(Node* &head){
    //already empty
    if(head==NULL)
        return;

    //if ll has only 1 element
    if(head->next==NULL){
        delete head;
        head =NULL;
    }


   Node* temp =head;
    head =head->next;
    delete temp;


}

void deleteFromEnd(Node* &head){
    //already empty
    if(head==NULL)
        return;

    //if ll has only 1 element
    if(head->next==NULL){
        delete head;
        head =NULL;
    }

    Node* prev =NULL;  //to point to second last node
    Node* curr=head;    //to point to last node
    while(curr->next!=NULL){
        prev =curr;
        curr = curr->next;
    }

    //there is nothing after second last node now
    prev->next =NULL;
    delete curr;  //delete from dma too


}

Node* reverseLL(Node* head){
    Node* curr=head;
    Node* prev =NULL;
    while(curr!=NULL){
        //store next first else we will loose it
        Node* n = curr->next;

        //current node ko reverse karo
        curr->next = prev;

        //next node ko reverse karo
        prev=curr;
        curr =n;
    }

    //prev is our new head so return it
    return prev;
}

Node* reverseRecLL(Node* head,Node* &newHead){
  if(head==NULL){
    newHead=NULL;
    return newHead;
  }

  //check if it is last node,if it is then make it head
  if(head->next==NULL){
    newHead=head;
    return newHead;
  }

  //reverse everything except current node
  Node* restTail = reverseRecLL(head->next,newHead);
  restTail->next = head;
  head->next =NULL;
  return head;

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

int main(){
  Node* head=NULL;  //first node ka address
  Node* tail =NULL; //last node ka address
 // Node* h1=NULL;
  insertAtStart(head,4);
  insertAtStart(head,3);
   insertAtStart(head,2);
  insertAtStart(head,1);

    //insertAtEnd(head,5);
  //insertAtEnd(head,6);

 // insertAtAnyPos(head,5,2);

  //deleteFromStart(head);
  //deleteFromStart(head);
  //deleteFromEnd(head);
  //deleteFromEnd(head);


  //printLL(head);
  /*Node* temp = searchLL(head,9);

  if(temp!=NULL)
    cout << temp->val << endl;
  else
    cout << "doesn't exist" << endl;


 // cout << Length(head) << endl; */
   //Node* newHead=NULL;
  //reverseRecLL(head,newHead);
 // printLL(newHead);

 Node* mid = getMid(head);
 cout << mid->val << endl;

}

