#include<bits/stdc++.h>
#define Fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Freed freopen("0in.txt", "r", stdin);
#define Fout freopen("0out.txt", "w", stdout);
#define ll long long int
#define pb push_back
#define pi acos(-1.0)
#define inf 1e18
#define Mod 1000000007
#define limit 1000008

#define  nl "\n"
using namespace std;
const int mod = 32768;
int d[mod];
vector<int>g[mod];

int p(int n,int c)
{
    for(int i=2;i<=c;i++)
    {
        n=n<<1;
    }
    return n;
}

int32_t main()
{
    Fast
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    for(int i=0;i<mod;i++)
    {
        g[(i+1)%mod].pb(i);
        g[i*2%mod].pb(i);
        d[i] = mod *10;
    }

    queue<int> q;
    q.push(0);
    d[0] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v: g[u])
        {
            if(d[u]+1<d[v])
            {
                d[v] = d[u] +1;
                q.push(v);
            }
        }
    }

    int t;cin>>t;
    while(t--)
    {
        int x;cin>>x;
        cout<<d[x]<<' ';
    }
    return 0;
}
