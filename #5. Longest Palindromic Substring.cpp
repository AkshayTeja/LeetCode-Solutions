class Solution
{
public:
    string longestPalindrome(string s)
    {
        int low, high, length = 1, startIndex = 0;
        for (int i = 0; i < s.size(); i++)
        {
            low = i;
            high = i + 1;
            while (low >= 0 && high < s.size() && s[low] == s[high])
            {
                if (high - low + 1 > length)
                {
                    length = high - low + 1;
                    startIndex = low;
                }
                low--;
                high++;
            }

            low = i;
            high = i;
            while (low >= 0 && high < s.size() && s[low] == s[high])
            {
                if (high - low + 1 > length)
                {
                    length = high - low + 1;
                    startIndex = low;
                }
                low--;
                high++;
            }
        }
        return s.substr(startIndex, length);
    }
};

class Solution
{
public:
    string expandFromCenter(int left, int right, string s)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";
        string longest = "";
        for (int i = 0; i < s.size(); i++)
        {
            string p1 = expandFromCenter(i, i, s);
            string p2 = expandFromCenter(i, i + 1, s);
            if (p1.size() > longest.size())
                longest = p1;
            if (p2.size() > longest.size())
                longest = p2;
        }
        return longest;
    }
};