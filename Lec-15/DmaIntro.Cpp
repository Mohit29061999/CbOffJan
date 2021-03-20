#include <iostream>
using namespace std;


int main(){
    //integer variable a is defined
   /* int *a=new int;  //a will store address of heap memory
    *a=10;
    cout << *a << endl; */
    int n;
    cin>>n;
    int *a=new int[n]; //store only first element address
    for(int i=0;i<n;i++){
        //a[i]=i+1; //equal to *(a+i)
        *(a+i)=i+1;  //ith element ka address
    }
    for(int i=0;i<n;i++){
        cout << *(a+i) << " ";
    }
}
