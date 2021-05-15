class Solution {
public:
    string longestPalindrome(string s) {
          int n=s.length();

          bool dp[n][n];  ///dp[i][j]: substring i to j is palindrome or not
                          ///if it is palindrome then true else false

         int l1=0;
        int st1=0;
          ///fill all substring with size 1
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            l1=1;
            st1=i;
        }

        ///fill all substring of size 2
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                l1=2;
                st1=i;
            }
            else
                dp[i][i+1]=false;
        }

        ///fill the remaining length substring ie. 3 to n
        for(int l=3;l<=n;l++){
            for(int st=0;st<=n-l;st++){
                int e=st+l-1;

                ///tell whether dp[st][e] is palindrome or not
                ///if s[st]==s[e] then dp[st][e]=dp[st+1][e-1]
                ///else dp[st][e]=false;

                if(s[st]==s[e]){
                    dp[st][e]=dp[st+1][e-1];
                    if(dp[st][e]==true){
                        l1=l;
                        st1=st;
                    }
                }
                else
                    dp[st][e]=false;


            }
        }

     /*   ///check all substring that are true and find the one with max length

        int st=0;  ///starting point of longest palindromic substring
        int l=0;  ///length of longest palindromic substring

        for(int i=0;i<n;i++){ ///susbtring starting at i
            for(int j=i;j<n;j++) {   ///substring ending at j
                 ///check if it is palindrome or not
                 if(dp[i][j]==true){
                     ///it is palindrome
                     if(l<j-i+1){
                         l=j-i+1;
                         st=i;
                     }
                 }
            }
        }
         */
        string ans="";
        ///print substring starting  at st index and of length l
        for(int i=0;i<l1;i++)
            ans+=s[st1+i];

        return ans;



    }
};
