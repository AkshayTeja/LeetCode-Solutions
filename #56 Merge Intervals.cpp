class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;

        if(intervals.empty())
            return ans;

        int n=intervals.size();
        vector<int> currentInterval=intervals[0];

        for(int i=1;i<n;i++)
        {
            if(currentInterval[1]>=intervals[i][0])
                currentInterval[1]=max(currentInterval[1],intervals[i][1]);
            else
            {
                ans.push_back(currentInterval);
                currentInterval=intervals[i];
            }
        }
        ans.push_back(currentInterval);
        return ans;
    }
};