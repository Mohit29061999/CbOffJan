#include <iostream>
using namespace std;

int length(char arr[]){
  int count =0;
  for(int i=0;arr[i]!='\0';i++)
    count++;
  return count;
}


int main(){
   char arr[100];
   int n;
   cin>>n;
   cin>>arr;
   int l=length(arr);
   for(int i=l-1;i>=0;i--)
    arr[i+n]=arr[i];  //shifting every element n places to right
   //take values from length index to length +n;
   int j=l;
   for(int i=0;i<n;i++){
   arr[i]=arr[j];
   j++;
   }
   arr[l]='\0';
   cout << arr << endl;



}





