//Solution with DFS

class Solution {
public:
    bool dfs(vector<int> &visited,vector<int> &pathVisited,
    int node,vector<int> &ans,vector<vector<int>> &adj)
    {
        visited[node]=1;
        pathVisited[node]=1;

        for(auto it:adj[node])
        {
            if(visited[it]==0)
            {
                if(dfs(visited,pathVisited,it,ans,adj))
                {
                    return true;
                }
            }
            else if(pathVisited[it]==1)
            {
                return true;
            }
        }
        pathVisited[node]=0;
        ans.push_back(node);
        return false;

    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto it:prerequisites) 
        {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(numCourses,0);
        vector<int> pathVisited(numCourses,0);
        vector<int> ans;

        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                if(dfs(visited,pathVisited,i,ans,adj))
                {
                    return {};
                }
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//Solution with BFS

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto it:prerequisites) 
        {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }

        if(ans.size()==numCourses)
            return ans;
        return {};
    }
};