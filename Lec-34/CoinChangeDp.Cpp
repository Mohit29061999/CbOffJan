///problem link: https://leetcode.com/problems/coin-change/

int dp[10001][13];  ///dp[i][j]: min ways to form amount i with j coins

int solve(vector<int> &v,int a,int i){
    ///base case:amount ==0 return 0;
    if(a==0)
        return 0;
    if(i==0)
        return INT_MAX;

    if(dp[a][i]!=-1)
        return dp[a][i];

    ///if it is not already solved
    ///use this coint
    dp[a][i]=INT_MAX;
    if(a>=v[i-1]){
        int y=solve(v,a-v[i-1],i);
        if(y!=INT_MAX)
            dp[a][i]=min(dp[a][i],y+1);
    }

    ///don't use this coin
    int y=solve(v,a,i-1);
    if(y!=INT_MAX){
         dp[a][i]=min(dp[a][i],y);
    }

    return dp[a][i];

}

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        for(int i=0;i<=amount;i++){
            for(int j=0;j<=n;j++)
                dp[i][j]=-1;
        }
        int y=solve(coins,amount,n);
        if(y==INT_MAX)
            return -1;
        return y;
    }
};
