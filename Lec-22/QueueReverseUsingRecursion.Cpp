#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int>&q){
    ///base case: if only 1 or 0 elements are there
    if(q.empty() || q.size()==1)
        return;

   ///tell  recursion to reverse everything except the first element
   int x=q.front();
   q.pop();
   reverseQueue(q);
   q.push(x);

}


int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverseQueue(q);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();

    }
}

