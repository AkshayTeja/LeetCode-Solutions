class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int exor=0;
        for(int i=0;i<nums.size();i++)
        {
            exor=exor^nums[i];
        }
        return exor;
    }
};