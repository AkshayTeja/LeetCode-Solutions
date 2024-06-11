class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans,res;
        for(int i=0;i<arr2.size();i++)
        {
            for(int j=0;j<arr1.size();j++)
            {
                if(arr1[j]==arr2[i])
                {
                    ans.push_back(arr1[j]);
                    arr1[j]=-1;
                }
            }
        }
        for(int i=0;i<arr1.size();i++)
        {
            if(arr1[i]!=-1)
            {
                res.push_back(arr1[i]);
            }
        }
        sort(res.begin(),res.end());
        for(auto it:res)
        {
            ans.push_back(it);
        }
        return ans;
    }
};