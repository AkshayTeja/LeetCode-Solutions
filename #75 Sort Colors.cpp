//Brute Solution is any sorting algorithm

//Better Solution
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int hash[3];
        for(int i=0;i<3;i++)
        {
            hash[i]=0;
        }
        for(int i=0;i<nums.size();i++)
        {
            hash[nums[i]]++;
        }
        int index=0,limit=0;
        for(int i=0;i<3;i++)
        {
            for(int j=index;j<hash[i]+limit;j++)
            {
                nums[index]=i;
                index++;
            }
            limit+=hash[i];
        }
    }
};

//Optimal solution using dutch national flag method
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid=0;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
                mid++;
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};