class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &visited,vector<vector<char>> &board,
    int helperRow[],int helperCol[],int n,int m)
    {
        visited[row][col]=1;
    
        for(int i=0;i<4;i++)
        {
            int r=row+helperRow[i];
            int c=col+helperCol[i];
            if(r>=0 && r<n && c>=0 && c<m && board[r][c]=='O' && !visited[r][c])
            {
                dfs(r,c,visited,board,helperRow,helperCol,n,m);
            }          
        }
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int helperRow[]={-1,0,1,0};
        int helperCol[]={0,1,0,-1};

        for(int j=0;j<m;j++)
        {
            if(!visited[0][j] && board[0][j]=='O')
                dfs(0,j,visited,board,helperRow,helperCol,n,m);
            if(!visited[n-1][j] && board[n-1][j]=='O')
                dfs(n-1,j,visited,board,helperRow,helperCol,n,m);
        }

        for(int i=0;i<n;i++)
        {
            if(!visited[i][0] && board[i][0]=='O')
                dfs(i,0,visited,board,helperRow,helperCol,n,m);
            if(!visited[i][m-1] && board[i][m-1]=='O')
                dfs(i,m-1,visited,board,helperRow,helperCol,n,m);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && !visited[i][j])
                    board[i][j]='X';
            }
        }
    }
};