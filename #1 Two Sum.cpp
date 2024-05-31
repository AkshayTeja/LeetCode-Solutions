//Brute Force Solution with O(N^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }

            }
        }
        return ans;
    }
};

//Better Solution with O(2N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hash;
        for(int i=0;i<nums.size();i++)
            hash[nums[i]]=i;
        for(int i=0;i<nums.size();i++)
        {
            int complement=target-nums[i];
            if(hash.find(complement)!=hash.end() && hash[complement]!=i)
            {
                return {i,hash[complement]};
            }
        }
        return {};
    }
};

//Optimal Solution with O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hash;
        for(int i=0;i<nums.size();i++)
        {
            int complement=target-nums[i];
            if(hash.find(complement)!=hash.end() && hash[complement]!=i)
            {
                return {i,hash[complement]};
            }
            hash[nums[i]]=i;
        }
        return {};
    }
};
