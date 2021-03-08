#include <iostream>
using namespace std;

int main(){
   int arr[3][3]={1,2,3,4,5,6,7,8,9};
    int r_s=0;
    int r_e=2; //n-1
    int c_s=0;
    int c_e=2;  //m-1;

    while(r_s<=r_e && c_s<=c_e){

        //print first row first
        for(int i=c_s;i<=c_e;i++)
            cout << arr[r_s][i] << " ";

        r_s++; //increase r_s as we have remaining first row

        //print last col
        for(int i=r_s;i<=r_e;i++)
            cout << arr[i][c_e] << " ";
        c_e--;

        //print last row and col in decreasing order
        if(r_s<=r_e){
        for(int i=c_e;i>=c_s;i--)
        cout << arr[r_e][i] << " ";
        r_e--;
        }

        //print first col and row in decreasing order
        if(c_s<=c_e){
        for(int i=r_e;i>=r_s;i--)
        cout << arr[i][c_s] << " ";
        c_s++;
        }
    }

}







