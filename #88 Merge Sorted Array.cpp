class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int zeroIndex=m;
        int index1=0,index2=0,flag=0;
        while(index2<n)
        {
            if(nums1[index1]==0 && index1>=zeroIndex)
            {
                flag=1;
                break;
            }
            if(nums1[index1]<=nums2[index2])
            {
                index1++;
            }
            else
            {
                for(int i=zeroIndex-1;i>=index1;i--)
                {
                    nums1[i+1]=nums1[i];
                }
                nums1[index1]=nums2[index2];         
                index1++;
                zeroIndex++;
                index2++;
            }
        }

        while(index2<n)
        {
            nums1[index1]=nums2[index2];
            index1++;
            index2++;
        }   
    }
};