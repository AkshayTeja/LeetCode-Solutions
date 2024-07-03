class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &ans,vector<vector<int>> &image,int color,
    int helperRow[],int helperCol[],int iniColor)
    {
        ans[row][col]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++)
        {
            int newRow=row+helperRow[i];
            int newCol=col+helperCol[i];
            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && image[newRow][newCol]==iniColor && ans[newRow][newCol]!=color)
            {
                dfs(newRow,newCol,ans,image,color,helperRow,helperCol,iniColor);
            }
        }

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor=image[sr][sc];
        vector<vector<int>> ans=image;
        int helperRow[]={-1,0,1,0};
        int helperCol[]={0,1,0,-1};
        dfs(sr,sc,ans,image,color,helperRow,helperCol,iniColor);
        return ans;
    }
};