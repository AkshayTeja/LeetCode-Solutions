class Solution
{
public:
    void backtrack(vector<int> &nums, vector<bool> &used, vector<int> &current, vector<vector<int>> &ans)
    {
        if (current.size() == nums.size())
        {
            ans.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
                continue;
            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, used, current, ans);
            used[i] = false;
            current.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);
        vector<int> current;
        vector<vector<int>> ans;
        backtrack(nums, used, current, ans);
        return ans;
    }
};