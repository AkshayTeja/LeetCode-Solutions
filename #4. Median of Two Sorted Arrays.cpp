class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> nums = nums1;
        for (int i = 0; i < nums2.size(); i++)
            nums.push_back(nums2[i]);
        int size = nums.size();
        sort(nums.begin(), nums.end());
        if (size % 2 == 0)
            return ((nums[size / 2] + nums[(size / 2) - 1]) / 2.0);
        else
            return nums[size / 2];
    }
};