class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> count;
        count[0]=1;
        int oddCount=0,ans=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==1)
            {
                oddCount++;
            }

            if(count.find(oddCount-k)!=count.end())
            {
                ans+=count[oddCount-k];
            }

            count[oddCount]++;
        }
        return ans;
    }
};