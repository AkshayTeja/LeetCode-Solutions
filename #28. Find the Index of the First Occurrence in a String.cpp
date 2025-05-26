class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int i = 0, j;
        while (i < haystack.size())
        {
            int index = i;
            for (j = 0; j < needle.size(); j++)
            {
                if (haystack[index] == needle[j])
                {
                    index++;
                    continue;
                }
                else
                {
                    break;
                }
            }
            if (j == needle.size())
            {
                return i;
            }
            i++;
        }
        return -1;
    }
};

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.size() > haystack.size())
            return -1;
        for (int i = 0; i <= haystack.size() - needle.size(); i++)
        {
            if (haystack.substr(i, needle.size()) == needle)
                return i;
        }
        return -1;
    }
};