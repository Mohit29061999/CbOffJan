#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    int a1[n+m];
    for(int i=0;i<n;i++)
        cin>>a1[i];
     int a2[m];
    for(int i=0;i<m;i++)
        cin>>a2[i];

    int i,j,k;
    i=n-1;
    j=m-1;
    k=n+m-1;

    while(j>=0 && i>=0){
        //compare which is greater
        if(a1[i]>=a2[j]){
            a1[k]=a1[i];
            i--;
        }
        else{
              a1[k]=a2[j];
            j--;
        }
        k--;
    }

    //add remaining elements of a2 array
    while(j>=0){
        a1[k]=a2[j];
        j--;
        k--;
    }

    for(int i=0;i<n+m;i++)
        cout << a1[i] << " ";






}



