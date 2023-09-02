#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

void solve()
{
    ll n,k;
    cin>>n>>k;
    ll a[n+3];
    ll b[n+3];
    for(int i = 0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                swap(a[i],a[j]);
                swap(b[i],b[j]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(k>=a[i])
        {
            k+=b[i];
        }
    }
    cout<<k<<endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ll t;
    cin>>t;
    while(t--)
    {
        solve();

    }
}