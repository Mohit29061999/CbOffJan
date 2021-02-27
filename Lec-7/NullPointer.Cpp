#include <iostream>
using namespace std;
int main(){
    //NUll means not pointing to anything
    int *p=NULL;  //pointer to integer type
    int x=5;
    p=&x;
    cout << p+1  << endl;
    cout << &x+1  << endl;

}





