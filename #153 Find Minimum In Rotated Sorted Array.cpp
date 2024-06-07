class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1,ans=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;

            //Left half sorted
            if(nums[low]<=nums[mid])
            {
                ans=min(nums[low],ans);
                low=mid+1;
            }
            //Right half sorted
            else if(nums[mid]<=nums[high])
            {
                ans=min(nums[mid],ans);
                high=mid-1;              
            }
        }
        return ans;
    }
};