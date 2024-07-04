class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans=mat;
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }

        int helperRow[]={-1,0,1,0};
        int helperCol[]={0,1,0,-1};
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            ans[row][col]=dis;

            for(int i=0;i<4;i++)
            {
                int newRow=row+helperRow[i];
                int newCol=col+helperCol[i];
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && mat[newRow][newCol]==1 && visited[newRow][newCol]!=1)
                {
                    q.push({{newRow,newCol},dis+1});
                    visited[newRow][newCol]=1;
                }
            }
        }

        return ans;

    }
};