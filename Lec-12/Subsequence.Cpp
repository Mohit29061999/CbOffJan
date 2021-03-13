#include <iostream>
using namespace std;


void printSub(char arr[],int i,char out[],int j){
    //ith index ka decision le rahe ho ie.to include it or not
    //j position where to add that element
    //base case
    if(arr[i]=='\0'){
        out[j]='\0';
        cout << out << endl; //print current subsequence
        return;
    }

    //case 1: add ith character
    out[j]=arr[i];
    printSub(arr,i+1,out,j+1);

    //case 2:don't add ith character
    printSub(arr,i+1,out,j);

}

int main(){
     char arr[100];
     cin>>arr;

     char out[100];//to store subsequence

     printSub(arr,0,out,0);


}



