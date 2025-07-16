class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int ans = nums[0], max_so_far = nums[0], min_so_far = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int current = nums[i];
            if (current < 0)
                swap(max_so_far, min_so_far);
            max_so_far = max(current, current * max_so_far);
            min_so_far = min(current, current * min_so_far);
            ans = max(ans, max_so_far);
        }
        return ans;
    }
};