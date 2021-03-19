#include <iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5,6};
    int n=6;
    int x=5;
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid]==x){
            cout << mid << endl;
            return 0;
        }

        if(arr[mid]>x){
            //go to left side
            e=mid-1;
        }
        else{
            //mid is smaller than target value
            //go to right side
            s=mid+1;
        }
    }

    //this means value doesn't exist
    cout << -1 << endl;

}

