//problem link: https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        int ans =0;
        int l[n],r[n];
        ///l[i]: numbers of bars by which we can extend the ith bar to left
        ///r[i]: numbers of bars by which we can extend the ith bar to right
        stack<int>s;

        l[0]=1;
        s.push(0);
        for(int i=1;i<n;i++){
            ///remove all greater bar to the left as they are useless now
            while(!s.empty() && heights[s.top()]>=heights[i])
                s.pop();

            ///this bar is smallest then we can extend it till 0th index
            if(s.empty()){
                l[i]=i+1;
            }
            else
                l[i]=i-s.top();  ///else s.top() is smaller than this bar
            s.push(i);
        }

        while(!s.empty())
            s.pop();

        r[n-1]=1;
        s.push(n-1);
        for(int i=n-2;i>=0;i--){
            ///remove all greater bar to the right as they are useless now
            while(!s.empty() && heights[s.top()]>=heights[i])
                s.pop();

             ///this bar is smallest then we can extend it till last index
            if(s.empty()){
                r[i]=n-i;
            }
            else
                r[i]=s.top()-i;  ///else s.top() is smaller than this bar
            s.push(i);
        }

        ///try the answer value for different bar as height
        for(int i=0;i<n;i++){
            ///-1 as that bar is inclued in both left and right extension
            ans = max(ans,(l[i]+r[i]-1)*heights[i]);
        }

        return ans;
    }
};
