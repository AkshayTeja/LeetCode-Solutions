class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        long long ans=0;
        for(int j=0;j<worker.size();j++)
        {
            long long maxProfit=0;
            for(int i=0;i<difficulty.size();i++)
            {
                if(profit[i]>maxProfit && worker[j]>=difficulty[i])
                {
                    maxProfit=profit[i];
                }
            }
            ans+=maxProfit;
        }
        return ans;
    }
};