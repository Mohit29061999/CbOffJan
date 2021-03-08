#include <iostream>
using namespace std;

bool isSorted(int arr[],int n,int i){
    //i is starting point of array to be checked
    //base case:if only 1 element left to check
    if(i==n-1)
        return true;

    //compare a[i] & a[i+1]
    if(arr[i]>arr[i+1])
        return false;

    //check for remaining array
    return isSorted(arr,n,i+1);

}



int main(){
    int arr[]={1,2,6,4,5};
    int n=5;
  if(isSorted(arr,n,0))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}




