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