class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long num=1;
        int ans=0,i=0;

        while(num<=n)
        {
            if(i<nums.size() && nums[i]<=num)
            {
                num+=nums[i];
                i++;
            }
            else
            {
                num+=num;
                ans++;
            }
        }
        return ans;
    }
};