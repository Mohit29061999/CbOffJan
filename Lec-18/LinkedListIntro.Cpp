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

int main(){
  Node n1(20);
  Node n2(30);

  n1.next = &n2; //to create link between n1 and n2

  //to print n2 data using n1
  //cout << (*(n1.next)).val << endl;
  cout << (n1.next)->val << endl;
  //jab object ka pointer h and uske through
  //object ki properties access karni h then use -> directly

}
