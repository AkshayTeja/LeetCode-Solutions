class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    visited[i][j]=1;
                } 
            }
        }

        int ans=0;
        int helperRow[]={-1,0,1,0};
        int helperCol[]={0,1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int time=q.front().second;
            ans=max(time,ans);
            q.pop();

            for(int i=0;i<4;i++)
            {
                int newRow=r+helperRow[i];
                int newCol=c+helperCol[i];
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol]==1 && visited[newRow][newCol]!=1)
                {
                    q.push({{newRow,newCol},time+1});
                    visited[newRow][newCol]=1;
                    grid[newRow][newCol]=2;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }

        return ans;

    }
};