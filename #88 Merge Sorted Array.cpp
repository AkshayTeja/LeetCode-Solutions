class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int zeroIndex = m;
        int index1 = 0, index2 = 0, flag = 0;
        while (index2 < n)
        {
            if (nums1[index1] == 0 && index1 >= zeroIndex)
            {
                flag = 1;
                break;
            }
            if (nums1[index1] <= nums2[index2])
            {
                index1++;
            }
            else
            {
                for (int i = zeroIndex - 1; i >= index1; i--)
                {
                    nums1[i + 1] = nums1[i];
                }
                nums1[index1] = nums2[index2];
                index1++;
                zeroIndex++;
                index2++;
            }
        }

        while (index2 < n)
        {
            nums1[index1] = nums2[index2];
            index1++;
            index2++;
        }
    }
};

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int j = 0, i = m; j < n; j++)
        {
            nums1[i] = nums2[j];
            i++;
        }
        sort(nums1.begin(), nums1.end());
    }
};

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (j >= 0)
        {
            if (i >= 0 && nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }
    }
};