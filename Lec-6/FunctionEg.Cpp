#include <iostream>
using namespace std;

//function defination
void printHello(){
    cout << "Hello World" << endl;
}

bool isPrime(int n){ //for void ,return is optinal else it is not

    for(int i=2;i<=n-1;i++){
        if(n%i==0){

           // return; //return : exit the function
           return false;
        }
    }
     //cout << "Yes it is";
     return true;
}
int main(){ //no need to call main else need calling
   // printHello();  //calling a function ie. exceute it
   //int n;
   //cin>>n;


}

