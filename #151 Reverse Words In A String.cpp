class Solution {
public:
    string reverseWords(string s) {
        vector<string> res;
        res.reserve(s.size() / 2);
        int i=0;
        while(i<s.size())
        {
            string word="";
            while (i < s.size() && s[i] == ' ') {
                i++;
            }
            while(i<s.size() && s[i]!=' ')
            {
                word+=s[i];
                i++;
            }
            while(i<s.size() && s[i]==' ')
            {
                i++;
            }
            res.push_back(word); 
        }
        string ans="";
        for(int i=res.size()-1;i>=0;i--)
        {
            ans+=res[i];
            if(i>0)
            {
                ans+=" ";
            }
        }
        return ans;
    }
};