#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf 1e18+18

using namespace std;

ll val[102];
ll wt[103];
ll dp[105][100050];
ll n,w;

ll knapsack(ll ii, ll w)
{
    if(i>n-1)
        return 0;
    if(dp[i][w]>0)
        return dp[i][w];
    ll x=-5,y;

    if(w+wt[i]<=w)
        x = val[i] + knapsack(i+1,w+wt[i]);
    y = knapsack(i+1,w);

    return dp[i][w] = max(x,y);
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n>>w;
    for(ll i=0; i<n; i++)
    {
        cin>>wt[i]>>val[i];
    }

    ll x = knapsack(0,0);

    cout<<x<<endl;
}


//void chmax(int &a, int b)
//{
//    a = max(a,b);
//}
//int INF = 1e15;
//int n,q;
//int w[100],v[100];
//int dp[300001];
//
//int main()
//{
//    int i,j;
//    cin>>n>>q;
//    for(i=0;i<n;i++)cin>>w[i]>>v[i];
//    for(i=0;i<=q;i++) dp[i] = -INF;
//    dp[0] = 0;
//
//    for(i=0;i<n;i++)
//    {
//        for(j=q;j>=0;j--)
//        {
//            chmax(dp[j+w[i]],dp[j]+v[i]);
//        }
//    }
//
//    int ans;
//    for(i=0;i<=q;i++) chmax(ans,dp[i]);
//    cout<<ans<<endl;
//    return 0;
//}
