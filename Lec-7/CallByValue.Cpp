#include <iostream>
using namespace std;

int  update(int a){
    a++;
    return a;
   // cout << a << endl;
}
void updateVar(int &a){
    a++;//& is must for call by reference
}
int main(){
    int n=5;
    //n=update(n);
    //cout <<n << endl;
    /*int &x=n;  //x is a refrence of n
    x++;*/
    updateVar(n);
    cout << n << endl;
}
