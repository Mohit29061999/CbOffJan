///problem link: https://leetcode.com/problems/stone-game/

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int dp[501][501];
      for(int i=0;i<=500;i++){
          for(int j=0;j<=500;j++)
              dp[i][j]=-1;
      }

        int sum =0;
        for(int i=0;i<n;i++)
            sum+=piles[i];

         ///when only one pile of stone is left
        for(int i=0;i<n;i++)
            dp[i][i]=piles[i];

        ///when two pile of stone are left
        for(int i=0;i<n-1;i++)
            dp[i][i+1]=max(piles[i],piles[i+1]);

        for(int l=3;l<=n;l++){
            for(int s=0;s<=n-l;s++){
                int e=s+l-1;

                ///take the first pile of stone
                int x=piles[s];
                //opponent can take first stone or last
                int y=min(dp[s+2][e],dp[s+1][e-1]);
                 dp[s][e]=x+y;
                  ///take the last coin
                x=piles[e];
                //opponent can take first coin or last
                 y=min(dp[s][e-2],dp[s+1][e-1]);

                dp[s][e]=max(dp[s][e],x+y);

            }
        }

        int x=dp[0][n-1];



        ///check if x is more than half stones or not
        if(x>=sum-x){
            return true;
        }
        return false;


    }
};
