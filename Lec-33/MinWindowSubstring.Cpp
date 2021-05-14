///problem link: https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();

        ///store count of characters in t
        int c1[256]={0};
        for(int i=0;i<m;i++)
            c1[t[i]]++;

        int c2[256]={0};  ///to store count of characters in current window

        int l=INT_MAX; ///to store ans
        int st1=0; ///to uniquely determine a substring , length and starting point
                  ///of substring,st will store starting point

        int st =0; ///starting point of the window

        for(int i=0;i<n;i++){
            ///try every index as ending point of the window
            //and calulate the min length of window ending at that index
            c2[s[i]]++;

            ///check if this window has all the characters or not
            bool hasAll = true;
            for(int j=0;j<256;j++){
                ///if jth character is required in more then what we have
                ///then this window doesn't has all the characters
                if(c1[j]>c2[j]){
                    hasAll = false;
                }
            }

            if(hasAll==true){
                ///try to reduce the window
                while(c2[s[st]]>c1[s[st]]){
                    c2[s[st]]--;
                    st++;
                }

                if(l>i-st+1){
                    l=i-st+1;
                    st1=st;
                }


            }


        }

        string ans ="";
        if(l==INT_MAX){
            return ans;
        }

        ///return that substring
        ///substring of length l and starting point st1
        for(int i=0;i<l;i++){
            ans+=(s[st1+i]);
        }

        return ans;
    }
};
