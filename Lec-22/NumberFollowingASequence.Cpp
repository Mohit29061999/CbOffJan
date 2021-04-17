//problem link: https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1#


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    string printMinNumberForPattern(string S){
        string s="";

        stack<int>st;
        int n= S.length();

        for(int i=0;i<=n;i++){
            st.push(i+1);

            ///if it is i or it is last ,then empty the stack
            /// as stack follows D by default( as numbers are inserted in increasing order)
            if(i==n || S[i]=='I'){
                while(!st.empty()){
                    s+=(st.top()+'0');
                    st.pop();
                }
            }
        }
        return s;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends
