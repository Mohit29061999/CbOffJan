///problem link: https://www.spoj.com/problems/MIXTURES/

#include <bits/stdc++.h>
using namespace std;

int sum[101][101];
int dp[101][101];

int solve(int a[],int i,int j){
    ///base case:when there is mixture left
    if(i==j)
    return 0;

  ///when two mixtures are left
    if(i+1==j){
        return a[i]*a[j];
    }

    if(dp[i][j]!=-1)
    return dp[i][j];
     int ans =INT_MAX;
    ///try every solution
    for(int k=i;k<j;k++){  /// k is giving left part ka last index

        ans = min(ans,solve(a,i,k)+solve(a,k+1,j)+sum[i][k]*sum[k+1][j]);

    }
    dp[i][j]=ans;
    return ans;

}

int main(){
int n;
while(cin>>n){  ///cin return null when there is no value
                ///else it gives not null
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        for(int i=0;i<=100;i++){
            for(int j=0;j<=100;j++){
                sum[i][j]=-1;
                dp[i][j]=-1;
            }
        }
        for(int i=0;i<n;i++)
        sum[i][i]=a[i];

        for(int l=2;l<=n;l++){
            for(int s=0;s<=n-l;s++){
                int e=s+l-1;
                sum[s][e]=(a[s]+sum[s+1][e])%100;
            }
        }

   cout << solve(a,0,n-1) << endl;



}
}
