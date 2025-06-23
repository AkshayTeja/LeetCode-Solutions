class Solution
{
public:
    void backtrack(vector<int> &candidates, int target, int start, vector<int> &current, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(current);
            return;
        }
        for (int i = start; i < candidates.size(); i++)
        {
            if (candidates[i] > target)
                continue;
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, current, ans);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> current;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, current, ans);
        return ans;
    }
};