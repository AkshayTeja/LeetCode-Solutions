class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            int j=0,nextEle=-1;
            while(nums2[j]!=nums1[i])
            {
                j++;
            }
            int currentEle=nums2[j];
            j++;
            while(j<nums2.size())
            {
                if(currentEle<nums2[j])
                {
                    nextEle=nums2[j];
                    break;
                }
                j++;
            }
            ans.push_back(nextEle);
        }
        return ans;
    }
};

//Another solution using maps & stacks
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mpp;
        vector<int> ans;
        stack<int> st;
        
        for(int num:nums2)
        {
            while(!st.empty() && st.top()<num)
            {
                mpp[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }

        while(!st.empty())
        {
            mpp[st.top()]=-1;
            st.pop();
        }

        for(int num:nums1)
        {
            ans.push_back(mpp[num]);
        }

        return ans;
    }
};