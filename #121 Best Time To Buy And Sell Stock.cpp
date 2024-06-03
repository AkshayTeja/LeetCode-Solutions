class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int minBuy=prices[0],profit=0,maxProfit=INT_MIN;
    for(int i=1;i<prices.size();i++)
    {
        profit=prices[i]-minBuy;
        minBuy=min(prices[i],minBuy);
        maxProfit=max(profit,maxProfit);
    }
    if(maxProfit>0)
        return maxProfit;
    return 0;
    }
};