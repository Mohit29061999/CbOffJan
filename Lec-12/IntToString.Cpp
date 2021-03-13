#include <iostream>
using namespace std;

void intToString(int n,string arr[]){
    //base case
    if(n==0)
        return;
    int x=n%10;
    intToString(n/10,arr);
    cout << arr[x] <<" ";
}

int main(){
    string arr[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
     intToString(4023,arr);
}
