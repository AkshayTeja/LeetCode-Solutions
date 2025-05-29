class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    int index=-1;
    int n=nums.size();
    for(int i=n-2;i>=0;i--)
    {
        if(nums[i]<nums[i+1])
        {
            index=i;
            break;
        }
    }
    if(index==-1)
    {
        reverse(nums.begin(),nums.end());
        return;
    }

    for(int i=n-1;i>index;i--)
    {
        if(nums[i]>nums[index])
        {
            swap(nums[i],nums[index]);
            break;
        }
    }

    reverse(nums.begin()+index+1,nums.end());
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-1;
        while(i>0 && nums[i-1]>=nums[i])
            i--;
        if(i==0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int j=nums.size()-1;
        while(j>=i && nums[j]<=nums[i-1])
            j--;
        swap(nums[j],nums[i-1]);
        reverse(nums.begin()+i,nums.end());
    }
};