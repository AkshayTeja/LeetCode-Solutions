class Solution {
public:
    bool isValid(string s) {
        stack <char> st;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else if(s[i]==')' || s[i]=='}' || s[i]==']')
            {
                if(st.empty())
                    return false;
                char temp=st.top();
                st.pop();
                if(s[i]==')' && temp!='(')
                {
                    return false;
                }
                if(s[i]=='}' && temp!='{')
                {
                    return false;
                }
                if(s[i]==']' && temp!='[')
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};