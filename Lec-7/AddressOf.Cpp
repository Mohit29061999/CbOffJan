#include <iostream>
using namespace std;


int main(){
   int x=5;
   char c='b';
   float f=3.14;
   //int arr[]={1,2,3,4,5,6,7};
   char arr[4]={'a','b','c','d'};
   cout << arr << endl;  //arr name = 0th element ka address
  // cout << &x << endl;
   //cout << &f << endl;  //address of
  // cout << &c << endl;//can't print address of character using &
  cout << (float *)&c << endl;
   float f1=3.14444;
   cout << f1 << endl;

}


