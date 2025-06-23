class Solution
{
public:
    bool isPalindrome(string &s, int start, int end)
    {
        while (start < end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
    void backtrack(string &s, int start, vector<string> &current, vector<vector<string>> &ans)
    {
        if (start == s.size())
        {
            ans.push_back(current);
            return;
        }
        for (int end = start; end < s.size(); end++)
        {
            if (isPalindrome(s, start, end))
            {
                current.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, current, ans);
                current.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> current;
        backtrack(s, 0, current, ans);
        return ans;
    }
};