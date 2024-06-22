class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int> st;
        
        for (int i=0;i<n;i++) {
            int curr=asteroids[i];

            while(!st.empty() && st.top()>0 && curr<0) 
            {
                if (st.top()<abs(curr)) 
                {
                    st.pop(); 
                    continue;
                } 
                else if(st.top()==abs(curr)) 
                {
                    st.pop();
                }
                curr=0;
            }
            
            if (curr!=0) {
                st.push(curr);
            }
        }
        
        vector<int> ans(st.size());
        for (int i=ans.size()-1;i>=0;i--) 
        {
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};
