#include <iostream>
using namespace std;

class Queue{
private:
    int cs;
    int f;
    int e;
    int* arr;
    int n;

public:
    Queue(int size){
        arr=new int[size];
        cs=0;
        e=-1;
        f=0;
        n=size;
    }

    void push(int val){
        if(cs==n){
            cout << "Queue is filled" << endl;
            return;
        }
        cs++;
        e=(e+1)%n;
        arr[e]=val;
    }

    void pop(){
        if(cs==0)
            return;
        cs--;
        f=(f+1)%n;
    }

    int size(){
        return cs;
    }

    int front(){
    return arr[f];}

    bool empty(){
        return cs==0;
    }

};

int main(){
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();

    }
}
