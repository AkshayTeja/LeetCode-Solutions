class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mpp;
        for(int i=0;i<edges.size();i++)
        {
            for(int j=0;j<edges[0].size();j++)
            {
                mpp[edges[i][j]]++;    
            }
        }
        for(auto it:mpp)
        {
            if(it.second==edges.size())
                return it.first;
        }
        return -1;
    }
};