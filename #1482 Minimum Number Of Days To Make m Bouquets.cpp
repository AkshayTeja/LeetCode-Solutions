class Solution {
public:
    int getNumOfBouquets(vector<int>& bloomDay, int mid, int k)
    {
        int num=0,count=0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=mid)
            {
                count++;
            }
            else
            {
                count=0;
            }
            if(count==k)
            {
                num++;
                count=0;
            }
        }
        return num;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=0,high=0;
        for(int day:bloomDay)
            high=max(high,day);
        
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;

            if(getNumOfBouquets(bloomDay,mid,k)>=m)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;     
    }
};