class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long power=0,num=0;
        while(num<=n)
        {
            num=pow(2,power);
            if(num==n)
            {
                return true;
            } 
            power++;
        }
        return false;
    }
};

//Optimal using Bit Manipulation

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        return (n & (n-1))==0;
    }
};