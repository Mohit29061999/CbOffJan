#include <iostream>
using namespace std;
//prototype it
bool isEven(int n);
int main(){
    //call karne se pahle function ko define karna hota h
    //or atleast prototype it
    if(isEven(2)){
        cout << "yes" << endl;
    }
    else
        cout << "No" << endl;
}
bool isEven(int n){
    if(n%2==0)
        return true;
    else
        return false;
}
