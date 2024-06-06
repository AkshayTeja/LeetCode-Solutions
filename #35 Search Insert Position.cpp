class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1,flag=0;
        int mid=(low+high)/2;
        while(low<=high)
        {
            if(nums[mid]==target)
            {
                flag=1;
                break;
            }
            else if(target>nums[mid])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
            mid=(low+high)/2;
        }
        if(flag==1)
        {
            return mid;
        }
        return low;
    }
};

//Another solution using lower bound code
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0,n=nums.size(),high=n-1,mid,ans;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>=target)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;  
    }
};