#include <iostream>
using namespace std;

int fibo(int n){
    //base case
   if(n==1)
       return 1;
    if(n==0)
        return 0;

    //simple case
    int ans =fibo(n-1)+fibo(n-2);
    return ans;
}


int main(){
    cout << fibo(5) << endl;
}


