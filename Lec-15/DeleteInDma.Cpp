#include <iostream>
using namespace std;


int main(){
    //integer variable a is defined
    int *a=new int;  //a will store address of heap memory
    *a=10;
     cout << *a << endl;

     delete a; //delete heap memory and not static;
    // a=NULL; //static variable pointer points to nothing

       //cout << *a << endl;

        int *arr=new int[10]; //store only first element address
        cout << arr << endl;
        delete []arr; //heap me array ko delete karo
        arr=NULL;  //static varible ie.pointer now points to nothing
        //cout << arr << endl;



}

