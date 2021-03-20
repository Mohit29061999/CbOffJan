#include <iostream>
using namespace std;

int* createArray(int n){
    //static memory get deleted at return statement
    //int a[10];
    //return a;  //Memory of variable a is deleted at this point
    int *a = new int[n];  //memory is dynamic
    for(int i=0;i<n;i++)
        a[i]=i+1;
    return a;
}

int main(){
    int* arr=createArray(10);
    for(int i=0;i<10;i++)
         cout << arr[i] << " ";
    cout << *a ; //a is a static varibale which points to heap memory
}

