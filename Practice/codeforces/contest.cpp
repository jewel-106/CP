#include <bits/stdc++.h>
using namespace std;
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    while(n--)
    {

        int a,k;
        cin>>a>>k;
        map<int,int>mp;
        mp.clear();
        for(int i=1; i<=a; i++)
        {
            int m,n;
            cin>>m>>n;

            for(int i=m;i<=n;i++)
            {
                mp[i]++;
            }
        }
        //sort(mp.begin(),mp.end());
        int cnt=0;
        int ind;
        cout<<endl;
        for(auto itt:mp)
        {
            cout<<itt.first<<" "<<itt.second<<endl;
        }
        cout<<endl;
        for(auto it:mp)
        {
            if(it.second>cnt)
            {
                cnt=it.second;
                ind = it.first;
            }

        }
        if(ind == k)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;


    }
    return 0;
}
