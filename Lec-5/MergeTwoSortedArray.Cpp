#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a1[n];
    for(int i=0;i<n;i++)
        cin>>a1[i];
     int a2[n];
    for(int i=0;i<n;i++)
        cin>>a2[i];

    int f[2*n];
    int i,j,k;
    i=j=k=0;
    while(i<n && j<n){
        //find min of both the array
        if(a1[i]<a2[j]){
            f[k]=a1[i];
            i++;
        }
        else{
             f[k]=a2[j];
            j++;
        }
        k++;
    }
     //as long as there are elements left in one of the array
     //add them to final array
    while(i<n){
        f[k]=a1[i];
        i++;
        k++;
    }
    while(j<n){
        f[k]=a2[j];
        j++;
        k++;
    }
   // for(int i=0;i<2*n;i++)
     //   cout << f[i] << " ";

    cout << f[n-1] << endl;





}


