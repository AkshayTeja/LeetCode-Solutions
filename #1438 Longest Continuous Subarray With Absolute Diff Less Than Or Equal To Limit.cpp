class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int left=0,ans=0;
        
        for (int right=0;right<nums.size();right++) 
        {
            while (!maxDeque.empty() && nums[maxDeque.back()]<=nums[right]) 
            {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);
            
            while (!minDeque.empty() && nums[minDeque.back()]>=nums[right]) 
            {
                minDeque.pop_back();
            }
            minDeque.push_back(right);
            
            while (nums[maxDeque.front()]-nums[minDeque.front()]>limit) 
            {
                if (maxDeque.front()==left) maxDeque.pop_front();
                if (minDeque.front()==left) minDeque.pop_front();
                left++;
            }

            ans= max(ans,right-left+1);
        }       
        return ans;
    }
};
