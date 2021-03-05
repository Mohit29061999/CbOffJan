//problem link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        
        int freq[256]={0};  //to store freq of every character in substring
        int st=0;  //substring ka starting point
        int ans =0;
        for(int i=0;i<n;i++){ //try every index as ending point of substring
        //check if current character is already present in substring
            while(freq[s[i]]>0){
                freq[s[st]]--; //move starting point one step ahead
                st++;
            }
            
            //include current character and make it ending point of substring
            freq[s[i]]++;
            ans = max(ans,i-st+1);
        }
    return ans;
    }
};