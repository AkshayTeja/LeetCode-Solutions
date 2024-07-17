class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        if(n!=1)
        {
            reverse(nums.begin()+(n-k),nums.end());
            reverse(nums.begin(),nums.begin()+(n-k));
            reverse(nums.begin(),nums.end());
        }       
    }
};