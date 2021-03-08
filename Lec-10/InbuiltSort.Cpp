#include <iostream>
#include <algorithm> //inbuilt sort header file
using namespace std;

bool compare(int x,int y){ //x is at smaller index
                           //y is at greater index
    //decreasing order
    //true means current ordering is correct
    //false means current ordering is incorrect
      return x<y;
}


int main(){
  int arr[]={5,-1,2,4,3,9};
  int n=6;

  //by default increasing order
  sort(arr,arr+n,compare);   //starting point and ending point where
                    //ending point is not included
  for(int i=0;i<n;i++)
    cout << arr[i] << " ";
}




