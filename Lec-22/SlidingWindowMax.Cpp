//problem link: https://leetcode.com/problems/sliding-window-maximum/#:~:text=You%20are%20given%20an%20array,Return%20the%20max%20sliding%20window.


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;

        vector<int>ans;
        ///insert the first window in deque
        for(int i=0;i<k;i++){
            ///remove all smaller element than current element in this window
            while(!dq.empty() && nums[dq.back()]<=nums[i])
                dq.pop_back();

            ///insert current element in deque
            dq.push_back(i);
        }

        ///insert the ans for first window
        ans.push_back(nums[dq.front()]);

        ///store the answer for other winodws too
        ///i-ending element for current window
        for(int i=k;i<n;i++){
            ///remove all elements that are no longer a part of this window
            int s=i-k+1;
             while(!dq.empty() && dq.front()<s)
                dq.pop_front();

              ///remove all smaller element than current element in this window
            while(!dq.empty() && nums[dq.back()]<=nums[i])
                dq.pop_back();

            dq.push_back(i);

                ///insert the ans for this window
        ans.push_back(nums[dq.front()]);




        }
        return ans;
    }
};
