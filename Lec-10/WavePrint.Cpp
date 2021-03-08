#include <iostream>
using namespace std;

int main(){
   int arr[][4]={1,2,3,4,5,6,7,8,9,10,11,12};
   //fix col first
   for(int c=0;c<4;c++){
    //print every rows of current col
    //if col even -print rows in increasing order
    //else odd-print rows in decreasing order
    if(c%2==0){
        for(int r=0;r<3;r++)
            cout << arr[r][c] << " ";
    }
    else{
        for(int r=2;r>=0;r--)
            cout << arr[r][c] << " ";
    }
   }

}






