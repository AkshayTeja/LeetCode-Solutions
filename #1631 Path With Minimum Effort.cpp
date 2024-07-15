class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> values(n,vector<int> (m,1e9));

        values[0][0]=0;
        pq.push({0,{0,0}});

        int helperRow[]={-1,0,1,0};
        int helperCol[]={0,1,0,-1};

        while(!pq.empty())
        {
            auto it=pq.top();
            int currentDiff=it.first;
            int row=it.second.first;
            int col=it.second.second;
            pq.pop();

            if(row==n-1 && col==m-1)
                return currentDiff;

            for(int i=0;i<4;i++)
            {
                int newRow=row+helperRow[i];
                int newCol=col+helperCol[i];

                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m)
                {
                    int newVal=max(abs(heights[newRow][newCol]-heights[row][col]),currentDiff);
                    if(newVal<values[newRow][newCol])
                    {
                        values[newRow][newCol]=newVal;
                        pq.push({newVal,{newRow,newCol}});

                    } 
                }
            }           
        }
        return 0;
    }
};