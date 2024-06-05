class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left=0,top=0,bottom=matrix.size()-1,right=matrix[0].size()-1;
        vector<int> ans; //Print as a 1-d array hence 1d vector enough
        while(left<=right && top<=bottom)
        {

            //for loop itself checks if left<=right or not for last iteration
            for(int i=left;i<=right;i++)
                ans.push_back(matrix[top][i]);
            top++;

            //for loop itself checks if top<=bottom or not for last iteration
            for(int i=top;i<=bottom;i++)
                ans.push_back(matrix[i][right]);
            right--;

            if(top<=bottom) //Only perform if top<=bottom i.e another row exists to iterate right to left
            {
                for(int i=right;i>=left;i--)
                   ans.push_back(matrix[bottom][i]);
            }
            bottom--;

            if(left<=right) //Only perform if left<=right i.e another column exists to iterate bottom to top
            {
                for(int i=bottom;i>=top;i--)
                    ans.push_back(matrix[i][left]);
            }   
            left++;
        }
        return ans;
    }
};