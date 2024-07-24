class DisjointSet
{
public:
    vector<int> parent,size;
    DisjointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUltParent(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node]=findUltParent(parent[node]);
    }

    void UnionBySize(int u,int v)
    {
        int ultparent_u=findUltParent(u);
        int ultparent_v=findUltParent(v);
        if(ultparent_u==ultparent_v)
            return;
        if(size[ultparent_u]<size[ultparent_v])
        {
            parent[ultparent_u]=ultparent_v;
            size[ultparent_v]+=size[ultparent_u];
        }
        else
        {
            parent[ultparent_v]=ultparent_u;
            size[ultparent_u]+=size[ultparent_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges=0;
        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findUltParent(u)==ds.findUltParent(v))
            {
                extraEdges++;
            }
            else
            {
                ds.UnionBySize(u,v);
            }
        }
        int connectedComponents=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)
            {
                connectedComponents++;
            }
        }
        int ans=connectedComponents-1;
        if(extraEdges>=ans)
            return ans;
        else
            return -1;
    }
};