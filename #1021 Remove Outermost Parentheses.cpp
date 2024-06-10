class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<char> left;
        string ans="";
        int i=0;

        while(i<s.size())
        {
                while(s[i]=='(')
                {
                    left.push_back(s[i]);
                    if(left.size()!=1)
                    {
                        ans=ans+s[i];
                    }
                    i++;  
                }
                while(s[i]==')')
                {
                    if(left.size()!=1)
                    {
                        ans=ans+s[i];    
                    } 
                    left.pop_back(); 
                    i++;      
                }
        }
        return ans;
    }
};