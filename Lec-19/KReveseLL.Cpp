
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

void insertAtEnd(Node* &head,int v){
     Node* n =new Node(v);

    //if linkedlist is empty
    if(head==NULL){
        head=n;
        return;
    }

    //to go to last node
    Node* curr=head;
    while(curr->next!=NULL){
        //move one step ahead
        curr=curr->next;
    }
    curr->next =n;
    //tail->next=n;
   // tail = n;
}





void printLL(Node* head){
    while(head!=NULL){
        cout << head->val << " "; //to print current node val
        head=head->next;  //to go to next node

    }
}

Node* kReverse(Node* head,int k){
	if(head==NULL)
	return head;

	//go k steps ahead
	Node* curr=head;
	for(int i=0;i<k;i++)
	curr=curr->next;

	//to reverse everything except first k
	Node* restLL = kReverse(curr,k);

	//reverse first k nodes
	Node* prev = NULL;
	int c=1;
	curr=head;
	while(c<=k){
		//reverse this node
		Node* n = curr->next;

		curr->next  = prev;

		//move to next node
		prev = curr;
		curr=n;
		c++;
	}


    //after reversing head is last node
	head->next = restLL;


	//give the final head
	return prev;
}

int main(){
  Node* head=NULL;  //first node ka address

  int n,k;
  cin>>n>>k;

  for(int i=0;i<n;i++){
	  int x;
	  cin>>x;
  insertAtEnd(head,x);
  }

  head=kReverse(head,k);
  printLL(head);



}

