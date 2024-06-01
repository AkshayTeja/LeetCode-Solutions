class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        vector<int> arr;
        for(int i=0;i<nums.size();i++)
            st.insert(nums[i]);
        for(auto it:st)
        {
            arr.push_back(it);
        }
        nums=arr;
        return nums.size();
    }
};