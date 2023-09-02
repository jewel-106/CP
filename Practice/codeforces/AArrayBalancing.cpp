
#include<bits/stdc++.h>
using namespace std;

int a[30],b[30];
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i = 1;i<=n;i++)
        {
            cin>>b[i];
        }

       long long ans = 0;
       for(int i = 2;i<=n;i++)
       {
            ans += min(abs(a[i] - a[i-1]) + abs(b[i] - b[i-1]), abs(a[i]- b[i-1]) + abs(b[i] - a[i-1]));
       }
       cout<<ans<<endl;
    }
    return 0;
}
