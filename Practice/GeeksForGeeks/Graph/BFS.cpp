
/// BFS Code in cpp.........
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution
{
public:
    vector<int> bfsofGraph(int V, vector<int> adj[],vector<int>& dis)
    {
        int s = 1;
        vector<bool> vis(V,0);
        vector<int> vec;
        queue<int> q;
        vis[s] = true;
        dis[s]=0;
        q.push(s);
        vec.push_back(s);

        while(!q.empty())
        {
            s = q.front();
            q.pop();

            for(auto child:adj[s])
            {
                if(!vis[child])
                {
                    vis[child]=true;
                    vec.push_back(child);
                    dis[child]=dis[s]+1;
                    q.push(child);
                }
            }

//            for (int i = 0; i < adj[s].size(); i++)
//            {
//                int child = adj[s][i];
//                if (vis[child] == 0)
//                {
//                    vis[child] = true;
//                    dis[child]=dis[s]+1;
//                    //vec.push_back(ad);
//                    q.push(child);
//                }
//            }
        }
        return vec;

    }
};
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tc;
    cin>>tc;
    while(tc--)
    {
        int V,E;
        cin>>V>>E;
        vector<int>adj[V];

        for(int i=0; i<E; i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int x;
        cin>>x;
        Solution obj;
        vector<int>dis(V,0);
        vector<int> ans = obj.bfsofGraph(V,adj,dis);
        for(int i=0; i<ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;

        cout<<dis[x-1];
        cout<<endl;
    }
    return 0;
}
