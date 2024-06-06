class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int preSum=0,count=0,n=nums.size();
        mpp[0]=1;
        for(int i=0;i<n;i++)
        {
            preSum+=nums[i];
            int remove=preSum-k;
            count+=mpp[remove];
            mpp[preSum]+=1;
        }
        return count;
    }
};