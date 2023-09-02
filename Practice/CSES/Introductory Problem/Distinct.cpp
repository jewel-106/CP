#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    cin>>n;
    set<ll> s;
    for(int i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        s.insert(a);
    }
    cout<<s.size()<<endl;

}
