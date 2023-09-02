
/// Cycle Detected in Directed Graph.........
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution
{
public:
    bool dfs(int node, vector<int> adj[], vector<bool> &vis, int parent)
    {
        vis[node] = true;
        // recS[node] = true;

        for (auto child : adj[node])
        {
            if (!vis[child])
            {
                if (dfs(child, adj, vis, node))
                    return true;
            }

            else if (child != parent)
                return true;
        }
        // recS[node] = false;
        return false;

        //        for(int i=0; i<adj[node].size(); i++)
        //        {
        //            int child = adj[node][i];
        //            if(vis[child]==0)
        //            {
        //                dfs(child,adj,vis,res);
        //            }
        //        }
    }
    bool dfsofGraph(int V, vector<int> adj[])
    {
        /// code is here
        vector<bool> vis(V, false);
        // vector<bool> recS(V,false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[child])
            {
                if (dfs(child, adj, vis, node))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        cout << obj.dfsofGraph(V, adj) << '\n';
    }
    return 0;
}
