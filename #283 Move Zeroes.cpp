class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index=-1,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                index=i;
                break;
            }    
        }

        if(index!=-1)
        {
            for(int i=index+1;i<n;i++)
            {
                if(nums[i]!=0)
                {
                    swap(nums[index],nums[i]);
                    index++;
                }
            }
        }     
    }
};