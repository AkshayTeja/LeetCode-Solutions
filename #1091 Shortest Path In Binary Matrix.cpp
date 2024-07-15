class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        if(n==1 && grid[0][0]==0)
            return 1;
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int> (n,1e9));

        dist[0][0]=1;
        q.push({1,{0,0}});

        int helperRow[]={-1,-1,-1,0,1,1,1,0};
        int helperCol[]={-1,0,1,1,1,0,-1,-1};

        while(!q.empty())
        {
            auto it=q.front();
            int dis=it.first;
            int row=it.second.first;
            int col=it.second.second;
            q.pop();

            for(int i=0;i<8;i++)
            {
                int newRow=row+helperRow[i];
                int newCol=col+helperCol[i];

                if(newRow>=0 && newRow<n && newCol>=0 && newCol<n && grid[newRow][newCol]==0 && dis+1<dist[newRow][newCol])
                {
                    dist[newRow][newCol]=dis+1;
                    if(newRow==n-1 && newCol==n-1)
                        return dis+1;
                    q.push({dis+1,{newRow,newCol}});
                }
            }           
        }
        return -1;
    }
};