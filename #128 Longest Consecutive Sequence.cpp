class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        int n=nums.size();
        if(n==0)
            return 0;

        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
        }
        int ans=1;
        for(auto it:st)
        {
            if(st.find(it-1)==st.end())
            {
                int cnt=1;
                int x=it;
                while(st.find(x + 1)!=st.end()) 
                {
                    x=x+1;
                    cnt=cnt+1;
                }
                ans=max(cnt,ans);
            }
        }
        return ans;
    }
};