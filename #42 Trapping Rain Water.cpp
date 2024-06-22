class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),ans=0;
        vector<int> leftMax(n),rightMax(n);
        leftMax[0]=height[0];
        rightMax[n-1]=height[n-1];

        for(int i=1;i<n;i++)
        {
            leftMax[i]=max(leftMax[i-1],height[i]);
        }

        for(int i=n-2;i>=0;i--)
        {
            rightMax[i]=max(rightMax[i+1],height[i]);
        }

        for(int i=1;i<n-1;i++)
        {
            int diff=min(leftMax[i],rightMax[i]);
            if(diff>height[i])
                ans+=diff-height[i];
        }
        return ans;
    }
};

//Optimal approach
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1,ans=0,maxleft=0,maxright=0;

        while(left<=right)
        {
            if(height[left]<=height[right])
            {
                if(height[left]>=maxleft)
                    maxleft=height[left];
                else
                    ans+=maxleft-height[left];
                left++;
            }
            else
            {
                if(height[right]>=maxright)
                    maxright=height[right];
                else
                    ans+=maxright-height[right];
                right--;
            }
        }
        return ans;
    }
};