class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> projects;
        for (int i = 0; i < profits.size(); i++) 
        {
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(),projects.end());
        
        priority_queue<int> maxHeap;
        int index = 0;
        
        while(k>0) 
        {
            while(index<projects.size() && projects[index].first<=w) 
            {
                maxHeap.push(projects[index].second);
                index++;
            }
            if (maxHeap.empty()) 
            {
                break;
            }
            w += maxHeap.top();
            maxHeap.pop();
            k--;
        }
        return w;
    }
};