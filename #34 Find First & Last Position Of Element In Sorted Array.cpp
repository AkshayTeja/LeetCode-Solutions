class Solution {
public:
    int lowerBound(vector<int>arr, int n,int target)
    {
        int low=0,high=n-1,mid,ans=n;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(arr[mid]>=target)
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

    int upperBound(vector<int>arr, int n,int target)
    {
        int low=0,high=n-1,mid,ans=n;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(arr[mid]>target)
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

    vector<int> searchRange(vector<int>& nums, int target) {
        int lb=lowerBound(nums,nums.size(),target);
        int ub=upperBound(nums,nums.size(),target);
        if(lb==nums.size() || nums[lb]!=target) 
        //Edge case when element not in array (lb=another number and not number itself)
        //or when lower bound is nth element
        {
            return {-1,-1};
        }
        return {lb,ub-1};
    }
};

//Another solution
class Solution {
public:
    int firstOccurence(vector<int>arr, int n,int target)
    {
        int low=0,high=n-1,mid,first=-1;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(arr[mid]==target)
            {
                first=mid;
                high=mid-1;
            }
            else if(arr[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return first;
    }

    int lastOccurence(vector<int>arr, int n,int target)
    {
        int low=0,high=n-1,mid,last=-1;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(arr[mid]==target)
            {
                last=mid;
                low=mid+1;
            }
            else if(arr[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first=firstOccurence(nums,nums.size(),target);
        if(first==-1)
        {
            return {-1,-1};
        }
        int last=lastOccurence(nums,nums.size(),target);
        return {first,last};
        }
};