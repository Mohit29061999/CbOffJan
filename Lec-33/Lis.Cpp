//problem link: https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        int dp[n];  ///dp[i]-lis ending at ith index
        dp[0]=1;

        for(int i=1;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                ///check if jth index can be placed before ith index
                if(nums[j]<nums[i] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
        }

        int ans =0;
        int index = 0;  ///ending point of lis
        vector<int> v; ///to store lis in reverse

        for(int i=0;i<n;i++){
           if(ans<dp[i]){
               ans = dp[i];
               index = i;
           }
        }

        v.push_back(nums[index]);
        ans--;
        index--;
        while(ans>0){
            ///can this be next element of lis(in reverse order)
            if(v[v.size()-1]>nums[index] && dp[index]==ans){
                //this is your next value
                v.push_back(nums[index]);
                ans--;
            }
            index--;
        }
        for(int i=0;i<v.size();i++)
            cout << v[i] << " ";
        return v.size();


    }
};


///memoised code
int dp[2500];  ///dp[i]: max length subsequence ending at ith index

int lis(vector<int> &v,int i){
    if(i==0)
        return 1;


    if(dp[i]!=-1){
        return dp[i];

    }
    int y=0;
    int ans =1;

  for(int j=0;j<i;j++){
             y= lis(v,j);
            if(v[j]<v[i]){
                ans = max(ans,y+1);
            }
  }

    dp[i]=ans;
    return dp[i];


}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       int n = nums.size();
        int res=1;
        for(int i=0;i<n;i++)
            dp[i]=-1;
        lis(nums,n-1);

        for(int i=0;i<n;i++){
            cout << dp[i] << " ";
            res=max(res,dp[i]);
        }
        return res;


    }
};
