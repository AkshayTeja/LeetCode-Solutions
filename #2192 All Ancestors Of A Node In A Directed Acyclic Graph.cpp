class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> in_degree(n,0);
        vector<set<int>> ancestors(n);
        
        for (auto edge:edges) 
        {
            int u=edge[0],v=edge[1];
            graph[u].push_back(v);
            in_degree[v]+=1;
        }

        queue<int> q;
        for (int i=0;i<n;i++) 
        {
            if (in_degree[i]==0) 
                q.push(i);
        }
        
        while (!q.empty()) 
        {
            int node=q.front();
            q.pop();
            
            for (int neighbor:graph[node]) 
            {
                ancestors[neighbor].insert(node);
                ancestors[neighbor].insert(ancestors[node].begin(),ancestors[node].end());
                in_degree[neighbor]-=1;
                
                if (in_degree[neighbor]==0)
                    q.push(neighbor);
            }
        }
        
        vector<vector<int>> result(n);
        for (int i=0;i<n;i++) 
        {
            result[i]=vector<int>(ancestors[i].begin(),ancestors[i].end());
        }
        return result;
    }
};