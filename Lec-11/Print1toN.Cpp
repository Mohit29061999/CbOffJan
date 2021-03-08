#include <iostream>
using namespace std;

void printNo(int no,int n){
    //base case:all numbers are printed
    if(no>n)
        return;

    //print number in hand
    cout << no << " ";
    //next number to be printed is no+1
    printNo(no+1,n);

}

void printNoReverse(int no,int n){
    //base case:all numbers are printed
    if(no>n)
        return;

       //next number to be printed is no+1
    printNoReverse(no+1,n);

    //print number in hand
    cout << no << " ";


}

int main(){
  printNo(1,5);
  cout << endl;
  printNoReverse(1,5);
}



