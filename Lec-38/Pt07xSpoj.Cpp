///problem link: https://www.spoj.com/problems/PT07X/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>> &v,int dp[][2],int i,int par){
    ///dp[i][0]:ith node is inclued 
    dp[i][0]=1;  ///ith node is included in vertex ;
    dp[i][1]=0;  ///ith node is not included
    
    for(int j=0;j<v[i].size();j++){
        ///check if it is not parent
        int y=v[i][j];
        if(y!=par){
            dfs(v,dp,y,i);
            dp[i][0]+=min(dp[y][0],dp[y][1]);  ///ith node is included so we have 
                                               ///choice to include yth node or not
            dp[i][1]+=dp[y][0];             ///ith node is not included so we have to keep 
                                            ///y
        }
    }
    
}
int main() {
   int n;
   cin>>n;
   
   vector<vector<int>>v;
   ///create an empty graph
   for(int i=0;i<n;i++){
       vector<int>temp;
       v.push_back(temp);
   }
   
    int dp[n][2];  ///dp[i][0]- min vertex to cover subtree with i as root with ith node included
                   ///dp[i][1]- min verex to cover subtree with ith node as root with ith node not included
   
    for(int i=0;i<n;i++){
        dp[i][0]=0;
        dp[i][1]=0;
    }
    
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        x--;  ///to convert  1 based indexing to 0 based indexing
        y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(v,dp,0,-1);
    cout << min(dp[0][0],dp[0][1]) << endl;
	return 0;
}