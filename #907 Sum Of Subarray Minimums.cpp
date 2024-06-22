class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        const int MOD = 1000000007;
        long ans=0;
        stack<int> st;

        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && (i==n || arr[i]<arr[st.top()]))
            {
                int j=st.top();
                st.pop();
                int left= !st.empty() ? st.top() : -1;
                ans=(ans+(long)arr[j]*(i-j)*(j-left))%MOD;  
            }
            if(i<n)
            {
                st.push(i);
            }
            
        }
        return (int)ans;

    }
};