class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(grid[i][j]==1)
                    {
                        q.push({i,j});
                        visited[i][j]=1;
                    }  
                }
            }
        }

        int helperRow[]={-1,0,1,0};
        int helperCol[]={0,1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int newRow=r+helperRow[i];
                int newCol=c+helperCol[i];
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol]==1 && visited[newRow][newCol]!=1)
                {
                    q.push({newRow,newCol});
                    visited[newRow][newCol]=1;
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                    ans++;
            }
        }

        return ans;
    }
};