class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0,j;
        while(i<haystack.size())
        {
            int index=i;
            for(j=0;j<needle.size();j++)
            {
                if(haystack[index]==needle[j])
                {
                    index++;
                    continue;
                }
                else
                {
                    break;
                }
            }
            if(j==needle.size())
            {
                return i;
            }
            i++;
        }
        return -1;
    }
};