#include <iostream>
using namespace std;

void merge(int arr[],int s,int mid,int e){
    int n1=mid-s+1;
    int n2=e-mid; //e-(mid+1)-1
    int l[n1],r[n2]; //l to store left half and r to store right half

    for(int i=0;i<n1;i++)
        l[i]=arr[i+s];

     for(int i=0;i<n2;i++)
        r[i]=arr[i+mid+1];

    //to stored merged elements from s to end
    int k=s;  //first element will be stored at s

    //normal merge code
    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        if(l[i]<=r[j]){
            arr[k]=l[i];
            i++;
        }
        else{
            arr[k]=r[j];
            j++;
        }
      k++;
    }

    //add remaining element of left half
       while(i<n1){
            arr[k]=l[i];
            i++;
           k++;
       }

       //add remaining element of right half
       while(j<n2){
            arr[k]=r[j];
            j++;
           k++;
       }


}

void mergeSort(int arr[],int s,int e)
{  //base case: size is 1
    if(s==e)
        return;
    //divide array in two half
    int mid =(s+e)/2;
    //sort left half
    mergeSort(arr,s,mid);
    //sort right half
    mergeSort(arr,mid+1,e);

    //merge the two half
    merge(arr,s,mid,e);
}


int main(){
    int arr[6]={5,3,-1,2,1,0};
    int n=6;

    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++)
        cout << arr[i] << " ";

}


