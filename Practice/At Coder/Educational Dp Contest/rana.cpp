
#include<bits/stdc++.h>
#define ll long long int
#define inf 10000000000000
using namespace std;
void solve()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll n,m;
    cin>>n>>m;
    ll h[n+5];
    ll t[m+5];
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>t[i];
    }
    sort(h,h+n);
    for(int i = 0;i<m;i++)
    {
        
        int val = t[i];
        int j;
        int ck=0;
        for(j = n-1; j>=0;j--)
        {
            if(val>=h[j])
            {
                cout<<h[j]<<endl;
                h[j]=inf;
                ck=1;
                j=-1;
            }
        }
        if(j==-1 && ck==0)
            cout<<-1<<endl;
    }
}
int main()
{
    solve();
}
