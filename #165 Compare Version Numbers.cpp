class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int i = 0, j = 0, m = version1.size(), n = version2.size();
        while (i < m || j < n)
        {
            int num1 = 0, num2 = 0;
            while (i < m && version1[i] != '.')
            {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            while (j < n && version2[j] != '.')
            {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            if (num1 < num2)
                return -1;
            if (num1 > num2)
                return 1;
            i++;
            j++;
        }
        return 0;
    }
};