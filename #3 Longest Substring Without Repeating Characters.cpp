class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mpp;
        int maxAns=0,start=0;
        for(int end=0;end<s.size();end++)
        {
            char currChar=s[end];

            if(mpp.find(currChar)!=mpp.end() && mpp[currChar]>=start)
            {
                start=mpp[currChar]+1;
            }
            mpp[currChar]=end;
            maxAns=max(maxAns,end-start+1);
        }
        return maxAns;
    }
};