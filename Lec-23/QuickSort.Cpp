#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int partiton(int arr[],int s,int e){
    int pivot = arr[e];   ///keep last at its correct pos
    int leftBoundary = s-1;  ///last index of elements smaller than pivot


    for(int i=s;i<e;i++){
        ///if this element is smaller than pivot
        if(arr[i]<=pivot){
            leftBoundary++;  ///to keep this elements we have to increase the left boundary
            ///keep this element within left boundary
            swap(arr[i],arr[leftBoundary]);
        }
    }

    ///put last element at its correct position
    swap(arr[leftBoundary+1],arr[e]);
    return leftBoundary+1;
}

int RandomQuickSort(int arr[],int s,int e){
    srand(time(0));   ///to get different in each sequence of run of rand function
    int pivot =s+(rand())%(e-s); ///to make the value of random function within array index
    swap(arr[pivot],arr[e]);  ///to make pivot as last element
   return  partiton(arr,s,e);
}

void QuickSort(int arr[],int s,int e){
    if(s>=e)
        return;

    ///keep last element at its correct position
    int pivotIndex= RandomQuickSort(arr,s,e);
    ///sort the smaller portion and greater portion
    QuickSort(arr,s,pivotIndex-1);
    QuickSort(arr,pivotIndex+1,e);
}

int main(){
    int arr[]={4,5,1,2,3,6,9,3};
    int n=8;
    QuickSort(arr,0,n-1);
    for(int i=0;i<8;i++)
        cout << arr[i] << " ";
}
