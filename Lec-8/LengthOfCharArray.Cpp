#include <iostream>
using namespace std;

//int-length provide karna
//character array will do without it
int length(char arr[]){
  int count =0;
  for(int i=0;arr[i]!='\0';i++)
    count++;
  return count;
}

int main(){
  char arr[100];
  cin.getline(arr,100);
  cout << length(arr) << endl;
}

