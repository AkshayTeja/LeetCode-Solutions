class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        int val;
        for (int i = 0; i < prices.size(); i++)
        {
            val = 0;
            for (int j = i + 1; j < prices.size(); j++)
            {
                if (prices[j] <= prices[i])
                {
                    val = prices[j];
                    break;
                }
            }
            prices[i] = prices[i] - val;
        }
        return prices;
    }
};