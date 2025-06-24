class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for (int i = 0; i < k; i++)
            min_heap.push({0, -1});
        unordered_map<int, int> mpp;
        for (int num : nums)
            mpp[num]++;
        for (auto it : mpp)
        {
            int freq = it.second;
            int num = it.first;
            if (freq > min_heap.top().first)
            {
                min_heap.pop();
                min_heap.push({freq, num});
            }
        }
        vector<int> ans;
        while (min_heap.size())
        {
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return ans;
    }
};