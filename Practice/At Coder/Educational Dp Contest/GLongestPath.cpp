
#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf 1e18+18
#define pb push_back
#define foru(i,a,b) for(ll i=a;i<=b;i++)
#define ford(i,a,b) for(ll i=a;i>b;i--)
#define vt vector
using namespace std;
const int N = 200005;


ll d[N];
ll n,m,max1;
vt<ll>g[N];
ll ans = 0;
ll rec(ll x)
{
    if(d[x] >=0) return d[x];
    ll ret = 0;
    for(auto item:g[x])
    {
        ret = max(ret,rec(item)+1);
    }
    return d[x] = ret;
}

int main()
{
    memset(d,-1,sizeof d);
    cin>>n>>m;
    foru(i,0,m-1)
    {
        ll a,b;
        cin>>a>>b;
        g[a].pb(b);
    }
    foru(i,1,n)
    {
        ans = max(ans,rec(i));
    }
    cout<<ans<<endl;
}

