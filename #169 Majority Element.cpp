class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int ele = nums[0], count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == ele)
                count++;
            else
            {
                count--;
                if (count < 0)
                {
                    ele = nums[i];
                    count++;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == ele)
            {
                cnt++;
            }
        }
        if (cnt > (n / 2))
            return ele;
        return 0;
    }
};

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }
        for (auto it : mpp)
        {
            if (it.second > (nums.size() / 2))
                return it.first;
        }
        return 0;
    }
};