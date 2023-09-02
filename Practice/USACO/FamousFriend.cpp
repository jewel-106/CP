#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> graph;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll t,n,i,x,k,ans,pans,mem,a,b,c,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        graph g(n+1);
        ans = 1e9;
        for(i = 1; i<=n; i++)
            do
            {
                cin>>x;
                g[i].push_back(x);
            }while(cin.peek() != '\n' && cin.peek() !=EOF);
            for(i = 1;i<=n ;i++)
            {
                queue<ll>q;
                vector<bool>vis(n+1);
                pans = 0;
                k = 0;
                q.push(i);
                vis[i] = true;
                c = 1;
                while(!q.empty())
                {
                    k++;
                    while(c--)
                    {
                        a = q.front();
                        b = g[a].size();
                        x = 0;
                        for(j = 0;j<b;j++)
                        {
                            if(!vis[g[a][j]])
                            {
                                q.push(g[a][j]);
                                vis[g[a][j]] = true;
                                x++;
                            }
                        }
                        pans += k *x;
                        q.pop();
                    }
                    c = q.size();
                }
                if(pans < ans)
                {
                    ans = pans;
                    mem = i;
                }
            }
            double x = ans * 1.0 /  n;
            cout<<mem<<" "<<fixed<<setprecision(6)<<x<<'\n';
    }
    return 0;
}
