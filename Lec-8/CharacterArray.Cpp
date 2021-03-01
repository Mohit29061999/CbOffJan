#include <iostream>
using namespace std;
//getline ki implementation
void take(char arr[100],int max_s,char end){
       int i=0;
       char ch=cin.get(); //to not ignore spaces
       while(ch!=end){
        arr[i]=ch;
        ch=cin.get();
        i++;
       }
       arr[i]='\0';
}

int main(){
   // char arr[5]={'a','b','c','d','\0'};
 //  char arr[5]="abcd";
 char arr[100];
 //for(int i=0;i<6;i++)
  //  cin>>arr[i];
//arr[4]='\0';
//cin:white space ko bhi end consider karta h
//cin>>arr; //not valid for int array
//cin.getline(arr,100);
take(arr,100,'$');
 //cin>>arr;
    //null represent ending of char array
    cout << arr << endl;
}
