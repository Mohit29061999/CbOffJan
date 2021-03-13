#include <iostream>
using namespace std;

void innerLoop(int arr[],int i,int end){
    //base case
    if(i==end)
        return;
    if(arr[i]>arr[i+1])
        swap(arr[i],arr[i+1]);
    //recursion ko bolna h compare kare rest of the index
    innerLoop(arr,i+1,end);
}

void outerLoop(int arr[],int n,int i){ //i means current iteration of outer loop
      if(i==n-1)
        return;
      //do one iteration of inner loop
      innerLoop(arr,0,n-1-i);
      //do next iteration of outer loop
      outerLoop(arr,n,i+1);

}


int main(){
    int arr[6]={5,3,-1,2,1,0};
    int n=6;
    outerLoop(arr,n,0);
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
}

