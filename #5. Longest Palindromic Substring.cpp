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