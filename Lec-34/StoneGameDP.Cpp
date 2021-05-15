///problem link: https://leetcode.com/problems/stone-game/


int dp[501][501];  ///dp[i][j]: max coins that you can get for array[i:j]

int solve(vector<int> &v,int i,int j){
    ///base case
    if(i==j){
        ///one pile of stone left
        return v[i];
    }

    if(i+1==j){
        ///two pile of stone left
        return max(v[i],v[j]);  ///take the pile with max coins
    }

    if(dp[i][j]!=-1)
        return dp[i][j];

    ///take the first coin
    int x=v[i];
    ///oponent can take first coin or last coin
    int y=min(solve(v,i+2,j),solve(v,i+1,j-1));
    int first = x+y;

    ///take the last coin
    x=v[j];
      ///oponent can take first coin or last coin
     y=min(solve(v,i+1,j-1),solve(v,i,j-2));
    int last = x+y;

    dp[i][j]=max(first,last);
    return dp[i][j];



}
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
      for(int i=0;i<=500;i++){
          for(int j=0;j<=500;j++)
              dp[i][j]=-1;
      }

        int sum =0;
        for(int i=0;i<n;i++)
            sum+=piles[i];

        int x=solve(piles,0,n-1);

        ///check if x is more than half stones or not
        if(x>=sum-x){
            return true;
        }
        return false;


    }
};
