class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int moves=0;

        sort(nums.begin(),nums.end());

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
                continue;
            while(nums[i]<=nums[i-1])
            {
                nums[i]++;
                moves++;
            }   
        
        return moves;
    }
};

//Another Solution
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int moves=0;

        sort(nums.begin(),nums.end());

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<=nums[i-1])
            {
                int increase=nums[i-1]-nums[i]+1;
                nums[i]+=increase;
                moves+=increase;
            }
        }
        return moves;
    }
};