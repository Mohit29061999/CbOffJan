
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

//merge two sorted ll
Node* merge(Node* h1,Node* h2){
    //base case:when anyone of the ll is empty,return the other one(non-empty)
    if(h1==NULL)
        return h2;
    if(h2==NULL)
        return h1;

    //compare starting node of both the ll
    Node* temp;
    if(h1->val<h2->val){
        temp =h1;
        //recursion will merge everything except the smaller of the two
        Node* restHead=merge(h1->next,h2);
        temp->next = restHead;
        return  temp;  //temp is our new head
    }
    else{
        //h2 is smaller
         temp =h2;
        //recursion will merge everything except the smaller of the two
        Node* restHead=merge(h1,h2->next);
        temp->next = restHead;
        return  temp;  //temp is our new head
    }
}



Node* mergeSort(Node* head){
    //base case
    if(head==NULL || head->next==NULL)
        return head;

    //divide ll into two ll of size n/2
    Node* mid = getMid(head);
    Node* sh = mid->next;  //store starting node of second half

    //to break ll, make mid->next =NULL
    mid->next =NULL;

    //sort both the half
    //sort first half
    head=mergeSort(head);

    //sort second half
    sh = mergeSort(sh);

    //merge both sorted half
    head = merge(head,sh);

    return head;


}




int main(){
  Node* head=NULL;  //first node ka address

  insertAtStart(head,1);
  insertAtStart(head,2);
   insertAtStart(head,3);
  insertAtStart(head,4);

  head=mergeSort(head);


  printLL(head);



}

