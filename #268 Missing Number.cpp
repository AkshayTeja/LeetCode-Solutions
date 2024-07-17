class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(),xor1=nums[0],xor2=0;
        for(int i=1;i<n;i++)
        {
            xor1=xor1^nums[i];
        }
        for(int i=1;i<=n;i++)
        {
            xor2=xor2^i;
        }
        return xor1^xor2;
    }
};