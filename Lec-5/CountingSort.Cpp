#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int count[1000001]={0};
    //step 1: count of number of times every value is occuring
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }

    //step2: print each value number of times it is occuring
    //starting from 0,1,2,.....
    for(int i=0;i<1000001;i++){
        //number of times that number is coming
        int x=count[i];
        for(int j=1;j<=x;j++)
            cout <<i << " ";
    }

}
