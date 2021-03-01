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

bool isPalindrome(char a1[]){
    int l=length(a1);
    int i=0;
    int j=l-1;
    while(i<j){
        if(a1[i]!=a1[j])
            return false;
        i++;
        j--;
    }
    return true;
}


int main(){
   char arr[100];
   cin>>arr;

   if(isPalindrome(arr))
    cout << "YES" << endl;
   else
    cout << "NO" << endl;


}



