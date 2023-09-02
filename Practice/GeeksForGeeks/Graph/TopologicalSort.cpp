
/// Topological Sort in cpp........
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<int> adj[] ,vector<bool> &vis,stack<int>& st)
    {
        vis[node] = true;
        for (int i = 0; i < adj[node].size(); i++)
        {
            int child = adj[node][i];
            if (vis[child] == 0)
            {
                dfs(child,adj,vis,st);
            }
        }
        st.push(node);
    }
    vector<int> dfsofGraph(int V, vector<int> adj[])
    {
        /// code is here
        vector<bool> vis(V, false);
        vector<int> res;
        stack<int> st;
        vector<int> vec;

        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i,adj,vis,st);
            }
        }

        while(st.empty()== false)
        {
            vec.push_back(st.top());
            st.pop();
        }
        return vec;
    }
};

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
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
        vector<int> res = obj.dfsofGraph(V, adj);
        for(auto it: res)
            cout<<it<<' ';
        cout<<endl;

    }
    return 0;
}
