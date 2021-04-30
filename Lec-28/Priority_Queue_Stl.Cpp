#include <iostream>
#include <queue> /// header file for priority_queue
using namespace std;

///write priority_queue that works as  min heap based on x value
class Node{
public:
    int x;
    int y;

    Node(int a,int b){
        x=a;
        y=b;
    }
};


///to compare priority of two Node elements
class customCompare{
public:
    bool operator()(Node n1,Node n2){ ///n1 is parent and n2 is child
        ///return true means swap parent and child else false
        return n1.x>n2.x;  ///min heap based on x values

    }
};

int main(){
    ///by default max heap
   /* priority_queue<int>pq;
     pq.push(10);
    pq.push(5);
    pq.push(12);
    pq.push(25);
    pq.push(1); */

    ///to convert it to min heap
    ///first way: insert negative of value
   /* priority_queue<int>pq;
     pq.push(-10);
    pq.push(-5);
    pq.push(-12);
    pq.push(-25);
    pq.push(-1); */
   /* priority_queue<int,vector<int>,greater<int>>pq; // min heap

     pq.push(10);
    pq.push(5);
    pq.push(12);
    pq.push(25);
    pq.push(1); */

    priority_queue<Node,vector<Node>,customCompare>pq;
    Node n1(1,2);
    pq.push(n1);

    Node n2(0,10);
    pq.push(n2);

       Node n3(5,15);
    pq.push(n3);

     Node n4(-1,8);
    pq.push(n4);


    while(!pq.empty()){
        cout << (pq.top()).x  << " " <<(pq.top()).y << endl ;
        pq.pop();
    }
}
