class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mpp;
        mpp['I']=1;
        mpp['V']=5;
        mpp['X']=10;
        mpp['L']=50;
        mpp['C']=100;
        mpp['D']=500;
        mpp['M']=1000;
        int n=s.size(),sum=0;

        for(int i=0;i<n;i++)
        {
            if(i < n - 1 && s[i]=='I' && (s[i+1]=='V' || s[i+1]=='X'))
            {
                if(s[i+1]=='V')
                {
                    sum+=4;
                }
                else
                {
                    sum+=9;
                }
                i++;
                continue;
            }
            else if(i < n - 1 && s[i]=='X' && (s[i+1]=='L' || s[i+1]=='C'))
            {
                if(s[i+1]=='L')
                {
                    sum+=40;
                }
                else
                {
                    sum+=90;
                }
                i++;
                continue;
            }
            else if(i < n - 1 && s[i]=='C' && (s[i+1]=='D' || s[i+1]=='M'))
            {
                if(s[i+1]=='D')
                {
                    sum+=400;
                }
                else
                {
                    sum+=900;
                }
                i++;
                continue;
            }
            else
            {
                sum+=mpp[s[i]];
            }
        }
        return sum;
    }
};