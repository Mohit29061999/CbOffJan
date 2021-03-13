#include <iostream>
using namespace std;

bool comeAlready(char a[],int s,int e,char c){
    for(int i=s;i<e;i++){
        if(a[i]==c)
            return false;
    }

    return true;
}

void permutation(char a[],int i){  //ith index ka decision le rahe h
    //base case
    if(a[i]=='\0'){
        cout << a << endl;  ///print current permuatation
        return;
    }

    //try all remaining elements at ith position
    for(int j=i;a[j]!='\0';j++){
        if(comeAlready(a,i,j,a[j])){
        //try jth index element at ith index
        swap(a[i],a[j]);

        //recursion baaki index ka decision lega
        permutation(a,i+1);

        //backtracking
        swap(a[i],a[j]);
        }
    }
}


int main(){
     char arr[100];
     cin>>arr;

     permutation(arr,0);
}


