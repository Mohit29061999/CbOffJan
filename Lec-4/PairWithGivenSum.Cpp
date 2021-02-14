#include <iostream>
#include <climits>   //lib for INT_MAX and INT_MIN
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

        int target;
        cin>>target;


      for(int i=0;i<n-1;i++){
        int min_i = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_i]){
                min_i =j;
            }
        }
        if(min_i!=i){
        int temp=arr[min_i];
        arr[min_i]=arr[i];
        arr[i]=temp;
        }
    }

    int left=0;
    int right =n-1;
    while(left<right){
        int sum =arr[left]+arr[right];
        if(sum>target){
            right--;
        }
        else if(sum<target){
            left++;
        }
        else{
            //sum == target
            cout << arr[left] << " "<< arr[right] << endl;
            left++;
            right--;
        }
    }


}


