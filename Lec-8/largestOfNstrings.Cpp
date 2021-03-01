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

void copy(char toBeStoredIn[],char FromWhichToBeCopeid[]){
    int i=0;
    for(i=0;FromWhichToBeCopeid[i]!='\0';i++)
      toBeStoredIn[i]=FromWhichToBeCopeid[i];
     toBeStoredIn[i]='\0';
}
//true means first one is greater
bool compare(char a1[],char a2[]){
    int l1=length(a1);
    int l2=length(a2);
    int i=0;
    for(;i<min(l1,l2);i++){
        if(a1[i]>a2[i]){
            return true;
        }
         else if(a1[i]<a2[i]){
            return false;
        }

    }

    if(l1>l2)
        return true;
    else
        return false;

}

int main(){
  int n;
  cin>>n;
  char max_string[100];  //store maximum of n strings
  char arr[100];   //for input
  cin>>arr;
  copy(max_string,arr);  //assume first string is greater

  for(int i=1;i<n;i++){
    cin>>arr;
    //cout << arr << endl;
    if(compare(max_string,arr)==false){
        copy(max_string,arr);
    }
    //cout << max_string << endl;
  }

  cout << max_string << endl;

}


