class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> distance(n,1e9);
        distance[src]=0;

        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            int stops=node.first;
            int ele=node.second.first;
            int dist=node.second.second;

            if(stops>k)
                continue;
            for(auto it:adj[ele])
            {
                int adjNode=it.first;
                int edgeWeight=it.second;

                if(dist+edgeWeight<distance[adjNode] && stops<=k)
                {
                    distance[adjNode]=dist+edgeWeight;
                    q.push({stops+1,{adjNode,dist+edgeWeight}});
                }
            }
        }

        if(distance[dst]==1e9)
        {
            return -1;
        }
        return distance[dst];
    }
};