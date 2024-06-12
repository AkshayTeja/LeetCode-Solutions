class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int i=0,flag=1;
        while(i<strs[0].size())
        {
            string str=strs[0].substr(0,i+1);
            for(int j=1;j<strs.size();j++)
            {
                if(strs[j].substr(0,i+1)==str)
                {
                    continue;
                }
                flag=0;
                break;
            }
            if(flag==1)
            {
                ans=str;
            }
            else
                break;
            i++;     
        }
        return ans;
    }
};