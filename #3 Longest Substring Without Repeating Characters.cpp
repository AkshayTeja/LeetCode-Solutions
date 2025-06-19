class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> mpp;
        int maxAns = 0, start = 0;
        for (int end = 0; end < s.size(); end++)
        {
            char currChar = s[end];

            if (mpp.find(currChar) != mpp.end() && mpp[currChar] >= start)
            {
                start = mpp[currChar] + 1;
            }
            mpp[currChar] = end;
            maxAns = max(maxAns, end - start + 1);
        }
        return maxAns;
    }
};

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = INT_MIN;
        if (s.size() == 0)
            return 0;
        for (int i = 0; i < s.size(); i++)
        {
            set<char> st;
            st.insert(s[i]);
            int index = i, count = 1;
            while (st.find(s[index + 1]) == st.end() && index + 1 < s.size())
            {
                index++;
                st.insert(s[index]);
                count++;
            }
            ans = max(count, ans);
        }
        return ans;
    }
};