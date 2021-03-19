class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();

        int s=0;
        int e=n-1;

        while(s<=e){
            int mid =(s+e)/2;
            if(nums[mid]==target)
                return mid;

            //kya left half sorted h??
            if(nums[s]<=nums[mid]){
                //left half is sorted
                //kya value lie within sorted half
                if(nums[s]<=target && nums[mid]>=target){
                   e=mid-1; //go to left half
                }
                else
                    s=mid+1; //go to right half
            }
            else{
                 //right half is sorted
                //kya value lie within sorted half
                if(nums[mid]<=target && nums[e]>=target){
                   s=mid+1; //go to right half
                }
                else
                    e=mid-1; //go to left half
            }
        }

        return -1;
    }
};
