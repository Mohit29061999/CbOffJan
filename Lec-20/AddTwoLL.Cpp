
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

void swapNode(Node** a,Node** b){
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

Node* addSameSize(Node* h1,Node* h2,int &c){
    ///base case:
    if(h1==NULL)
        return h2;

    Node* res=new Node(0);  //make a temp node for this position

    ///recursion will add the rest of the nodes
    Node* restLL = addSameSize(h1->next,h2->next,c);

    int sum = h1->val +h2->val + c;
    c=sum/10;  ///update carry for next node
    sum = sum%10;
    res->val  = sum;
    res->next = restLL;
    return res;

}

void addRemNode(Node* h1,Node* cur,Node* &res,int &c){
    //base case
    if(h1==cur)
        return;

    addRemNode(h1->next,cur,res,c);  ///recursion will add rest of the nodes

    int s=h1->val+c;
    c=s/10;
    s=s%10;
    insertAtStart(res,s);

}

Node* addLL(Node* h1,Node* h2){
    //corner case
    if(h1==NULL)
        return h2;
    if(h2==NULL)
        return h1;

    int c=0;
    int n1=Length(h1);
    int n2=Length(h2);
    Node* res;
    if(n1==n2){
            //both ll are of same size
        res=addSameSize(h1,h2,c);

    }

    else{
        if(n1<n2)
            swap(&h1,&h2);

        int diff = abs(n1-n2);
        Node* cur=h1;
        for(int i=0;i<diff;i++)
            cur = cur->next;

        res=addSameSize(cur,h2);

        addRemNode(h1,cur,res,c);

    }

    if(c)
        insertAtStart(res,c);

    return res;


}


int main(){
  Node* head=NULL;  //first node ka address

  insertAtStart(head,4);
  insertAtStart(head,3);
   insertAtStart(head,4);
  insertAtStart(head,4);

 // bubbleSort(head);

  printLL(head);



}



