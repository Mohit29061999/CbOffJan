#include <iostream>
#include <climits>   //lib for INT_MAX and INT_MIN
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int max_v=INT_MIN;
    int count =0;
    for(int i=0;i<n;i++){
        if(arr[i]>max_v){
            //this means light will fall on ith building
            cout << arr[i] << " ";
            count++;
            max_v=arr[i];  //we found new max building
        }
    }
    //cout << count << endl;

}

