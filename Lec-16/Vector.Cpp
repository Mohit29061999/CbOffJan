#include <iostream>
using namespace std;

class Vector{
public:
    int ms;  //current vector ka size
    int cs;  //no of elements in vector currently
    int *arr;

    Vector(int ms=2){
       cs=0;
       this->ms=ms;
       //dma ke through array create kiya h
       arr=new int[this->ms];
    }

    void push_back(int val){
        if(cs==ms){
        //if array is completely filled,double its size
        int* oldArr=arr;
        arr=new int[ms*2]; //new array of size of double of previous one

        //copy contents from previous array to new one
        for(int i=0;i<cs;i++)
            arr[i]=oldArr[i];

        ms=ms*2;  //update max size
        delete []oldArr; //delete previous array
        }

        arr[cs++]=val;
    }

    void pop_back(){
        //try reducing size to half if more than half places are empty
        if(cs>0)
            cs--;
        return;
    }

    int size(){
        return cs;
    }

    //operator overloading
    //to give meaning to [] for vector
    int  operator[](int i){
        return arr[i];
    }

};

int main(){
Vector v;
for(int i=0;i<5;i++)
    v.push_back(i+1);
for(int i=0;i<5;i++)
    cout << v[i] << endl;
    //cout << v.arr[i] << " ";

    cout << v.ms << endl;

    for(int i=0;i<5;i++)
        v.pop_back();

    cout << v.cs << endl;




}

