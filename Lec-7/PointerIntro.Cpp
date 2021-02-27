#include <iostream>
using namespace std;
int main(){
    int *p;  //pointer to integer type
    int x=5;
    p=&x;  //value of p = x ka address
   // cout << p+1 << endl;  //x ka address print hoga
   // cout << &x+1 << endl;
   *p =*p+1;
  // cout << *p << endl;
   cout << x << endl;
}




