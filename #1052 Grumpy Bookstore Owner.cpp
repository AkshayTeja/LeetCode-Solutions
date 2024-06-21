class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int ans=0;

        for(int i=0;i<n;i++)
        {
           if(grumpy[i]==0)
            {
                ans+=customers[i];
            }
        }

        int extra=0,maxExtra=INT_MIN;
        for(int i=0;i<minutes;i++)
        {
            if(grumpy[i]==1)
            {
                extra+=customers[i];
            }
        }
        maxExtra=extra;

        for(int i=minutes;i<n;i++)
        {
            if(grumpy[i]==1)
            {
                extra+=customers[i];
            }
            if(grumpy[i-minutes]==1)
            {
                extra-=customers[i-minutes];
            }
            maxExtra=max(maxExtra,extra);
        }

        return ans+maxExtra;
    }
};