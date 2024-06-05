class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //Transpose
        int n=matrix.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++)
        {
            /*for(int j=0;j<(n/2);j++)
            {
                swap(matrix[i][j],matrix[i][n-j-1]);
            }*/
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};