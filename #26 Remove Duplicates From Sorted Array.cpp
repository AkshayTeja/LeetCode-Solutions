class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        set<int> st;
        vector<int> arr;
        for (int i = 0; i < nums.size(); i++)
            st.insert(nums[i]);
        for (auto it : st)
        {
            arr.push_back(it);
        }
        nums = arr;
        return nums.size();
    }
};

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        if (nums.empty())
            return 0;

        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[j] > nums[i])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};