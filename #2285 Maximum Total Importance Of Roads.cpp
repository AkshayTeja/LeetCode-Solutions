class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>degree(n,0);

        for(auto edge:roads)
        {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        sort(degree.begin(),degree.end());

        long long value=1,ans=0;
        for(long long d:degree)
        {
            ans+=(value*d);
            value++;
        }
        
        return ans;
    }
};