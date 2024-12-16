class Solution
{
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        for (int i = 0; i < k; i++)
        {
            int minVal = INT_MAX, index = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] < minVal)
                {
                    minVal = nums[j];
                    index = j;
                }
            }
            nums[index] = nums[index] * multiplier;
        }
        return nums;
    }
};