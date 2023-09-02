
#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf 1e18+18

using namespace std;
const int mx = 1e5+5;
int n,k,a[110],dp[110][mx];
int pref[110][mx];

signed main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<=k;i++)
    {
        if(i<=a[1]) dp[1][i] = 1;
    }
    for(int i=0;i<=k;i++)
    {
        if(i==0) pref[1][i] = dp[1][i];
        else pref[1][i] = (pref[1][i-1] + dp[1][i]) % mod;
    }

    for(int i= 2;i<=n;i++)
    {
        for(int j = 0;j<=k;j++)
        {
            dp[i][j] += pref[i-1][j] - (j - a[i] - 1<0 ? 0ll:pref[i-1][j-a[i]-1]);
            dp[i][j] = (dp[i][j] + mod) %mod;
            if(j==0) pref[i][j] = dp[i][j];
            else pref[i][j] = (pref[i][j-1] + dp[i][j]) %mod;
        }
    }
    cout<<dp[n][k]<<endl;
    return 0;
}
