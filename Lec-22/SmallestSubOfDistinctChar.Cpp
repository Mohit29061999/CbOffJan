class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.length();
        int count[256]={0};  ///this tells you count of a character in remaining string
        int used[256]={0};   /// whether a char is in solution or not

        for(int i=0;i<n;i++){
            count[s[i]]++;
        }
        stack<char>st;
        for(int i=0;i<n;i++){
            ///this character is no longer a part of remaining string,so count[s[i]]--;
            count[s[i]]--;

            ///if this is already used then ignore it as we want distinct char only
            if(used[s[i]])
                continue;

            ///see if we can replace some characters by this char
            ///ie.we can decrease our solution by using current char in place or some char
            /// only if current char is small and char to be replaced should be in
            /// remaining string
            while(!st.empty() && st.top()>s[i] && count[st.top()]>0){
                ///it is no longer a part of ans so change used
                used[st.top()]--;
                st.pop();
            }
            st.push(s[i]);
            used[s[i]]=1;
        }
        string ans ="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        ///ans has string in reversed order , so reverse it to get correct ans
        reverse(ans.begin(),ans.end());
        return ans;

    }
};
