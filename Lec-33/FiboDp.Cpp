#include <iostream>
using namespace std;

///step 1: write a recursive solution
///step 2: memoise it
int dp[100];   ///1<=n<=10^2

//top down : n-0
/*int fibo(int n){
    if(n==0 || n==1)
        return n;

    ///see if this problem is already calculated or not
    if(dp[n]!=-1)
        return dp[n];

    ///if it is first time being calculated then call its subproblem

    dp[n] =fibo(n-1)+fibo(n-2);
    return dp[n];
} */


///bottom up approach:0-n
int fibo(int n){
    int dp[n];
    for(int i=0;i<=n;i++)
        dp[i]=-1;

    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}

int main(){
         int n;
         cin>>n;
         for(int i=0;i<=n;i++){
            dp[i]=-1;
         }

        cout << fibo(n) << endl;

}
