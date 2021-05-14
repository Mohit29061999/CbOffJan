#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

int dp[1001][1001];  //dp[i][j]: max val for bag with weight i
                     //and j no of items

int solve(int w,int n,int wt[],int val[]){
    ///base case:
    ///we are using 1 based indexing
    if(w==0 || n==0) ///if remaining capacity is 0,then return 0
    return 0;         ///  ///if no elements are left then also you can't keep anything so 0

    ///check if this problem is already solved
    if(dp[w][n]!=-1)
    return dp[w][n];
    ///keep this item

    ///if it is not solved already then solve it
    int ans =0;
    if(wt[n-1]<=w){
        ans = solve(w-wt[n-1],n-1,wt,val)+ val[n-1];
    }
    //don't keep this item
    ans = max(ans,solve(w,n-1,wt,val));
    dp[w][n]=ans;
    return ans;


}

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
          int dp1[W+1][n+1];
          ///if weight is 0 then ans is 0
          for(int i=0;i<=n;i++)
          dp[0][i]=0;

          //if no of items is 0 then ans is 0
           for(int i=0;i<=W;i++)
          dp[i][0]=0;

          for(int i=1;i<=W;i++){
              for(int j=1;j<=n;j++){
                  dp[i][j]=0;
                  ///keep this item
                  if(i>=wt[j-1]){
                      dp[i][j]=dp[i-wt[j-1]][j-1]+val[j-1];
                  }

                  ///don't keep this item
                  dp[i][j]=max(dp[i][j],dp[i][j-1]);
              }
          }

       return dp[W][n];
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;

        int val[n];
        int wt[n];

        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];

        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;

    }
	return 0;
}  // } Driver Code Ends
