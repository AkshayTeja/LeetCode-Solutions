class Solution
{
public:
    bool dfs(vector<vector<int>> &graph, vector<int> &colors, int node, int color)
    {
        colors[node] = color;

        for (auto it : graph[node])
        {
            if (colors[it] == -1)
            {
                if (!dfs(graph, colors, it, !color))
                    return false;
            }
            else if (colors[it] == color)
                return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();

        vector<int> colors(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (colors[i] == -1)
                if (dfs(graph, colors, i, 0) == false)
                {
                    return false;
                }
        }

        return true;
    }
};

class Solution
{
public:
    bool bfs(vector<vector<int>> &graph, vector<int> &colors, int start)
    {
        queue<int> q;
        q.push(start);
        colors[start] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : graph[node])
            {
                if (colors[it] == -1)
                {
                    colors[it] = !colors[node];
                    q.push(it);
                }
                else if (colors[it] == colors[node])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> colors(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (colors[i] == -1)
                if (!bfs(graph, colors, i))
                    return false;
        }
        return true;
    }
};