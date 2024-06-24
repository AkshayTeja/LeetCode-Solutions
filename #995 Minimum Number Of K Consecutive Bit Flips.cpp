class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> is_flipped(n,0);
        int flips=0;
        int flip=0;

        for (int i=0;i<n;i++) 
        {
            if (i>=k) 
            {
                flip^=is_flipped[i - k];
            }

            if (nums[i] == flip) 
            { 
                if (i+k> ) 
                {  
                    return -1;
                }
                flips++;
                flip^= 1;
                is_flipped[i] = 1; 
            }
        }

        return flips;
    }
};