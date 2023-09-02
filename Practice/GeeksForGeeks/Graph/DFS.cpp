/// DFS code in cpp......
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<int> adj[],vector<bool> &vis,vector<int> &res)
    {
        vis[node] = true;
        res.push_back(node);

        for(auto child:adj[node])
        {
            if(!vis[child])
            {
                dfs(child,adj,vis,res);
            }
        }

//        for(int i=0; i<adj[node].size(); i++)
//        {
//            int child = adj[node][i];
//            if(vis[child]==0)
//            {
//                dfs(child,adj,vis,res);
//            }
//        }

    }
    vector<int> dfsofGraph(int V, vector<int> adj[])
    {
        /// code is here
        vector<bool> vis(V,false);
        vector<int> res;

        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                dfs(i, adj, vis, res);
            }
        }

        return res;
    }

};

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tc;
    cin>>tc;
    while(tc--)
    {
        int V,E;
        cin>>V>>E;
        vector<int> adj[V];

        for(int i=0; i<E; i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsofGraph(V,adj);
        for(int i = 0; i<ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
