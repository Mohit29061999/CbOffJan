#include <iostream>
using namespace std;


int main(){

 int n;
 cin>>n;
int j=10;
 //check all numbers from 2 to n
 //int i=2;
 for(int i=2;i<=n;i++){
        //check if i is prime or not
    int j=2;
  //  int j=2;
    while(j<=i-1){
        if(i%j==0)
            break;
        j++;
    }
    if(j==i){
        cout << i << " ";
    }

 }
 //cout << i << endl;







}




