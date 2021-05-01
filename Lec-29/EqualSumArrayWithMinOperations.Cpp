///problem link: https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/



class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        if(n*1>6*m || n*6<m*1)
            return -1;

        priority_queue<int>pq1;  ///max heap
        priority_queue<int,vector<int>,greater<int>>pq2; //min heap

        ///find sum of both the arrays
        int s1=0; ///sum of first array
        int s2=0;  ///sum of second array
        for(int i=0;i<n;i++)
            s1+=nums1[i];
        for(int i=0;i<m;i++)
            s2+=nums2[i];

        ///elements of array with greater sum in max heap
        ///and with smaller sum in min heap
        int s3=0; ///to store sum of max heap
        int s4=0; ///to store sum of min heap
        if(s1>s2){
            ///store elements of nums1 in max heap
            ///ans elements of nums2 in min heap
             for(int i=0;i<n;i++)
                pq1.push(nums1[i]);

             for(int i=0;i<m;i++)
                pq2.push(nums2[i]);

            s3=s1;  ///sum of elements of max heap
            s4 = s2; ///sum of min heap
        }
        else{
              ///store elements of nums2 in max heap
            ///ans elements of nums1 in min heap
             for(int i=0;i<n;i++)
                pq2.push(nums1[i]);

             for(int i=0;i<m;i++)
                pq1.push(nums2[i]);

            s3=s2;  ///sum of elements of max heap
            s4 = s1; ///sum of min heap

        }

        int ans =0;
        while(s3!=s4){
            ///remove top element from max heap and min heap
              int x=pq1.top();
            int y=pq2.top();


            int z=abs(s3-s4);

              ///can we reduce diff to 0 in this step
            ///x can be at best made to 1
            ///y can be at best made to 6
            if(x-1>=z || 6-y>=z)
                return ans+1;

            ///select the greater diff operation of the two
            ///ie.x -> 1 or y->6
            if(x-1>=6-y){
                pq1.pop();  ///remove x
                pq1.push(1); ///and insert in its place
                s3-=(x-1);
            }
            else{
                  pq2.pop();  ///remove y
                pq2.push(6);  ///ans insert 6 at its place
                s4+=(6-y);
            }
            ans++;
        }

        return ans;

    }
};
