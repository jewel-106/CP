#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    string s;
    cin>>s;
    int prev = -1;
    int res=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1')
        {
            if(prev!=-1) res+=(i-prev-1);
            prev=i;
        }
    }
    cout<<res<<endl;

}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
//void solve()
//{
//    ll n;
//    cin>>n;
//    ll a[n+3];
//    ll ind[n+5];
//    map<int,int>mp;
//    for(int i=1; i<=n; i++)
//    {
//        cin>>a[i];
//        ind[a[i]]=i;
//        mp[a[i]]++;
//    }
//    ll value;
//    ll indx = 0;
//    ll mn = INT_MAX;
//    ll ck=0;
//    for(auto it:mp)
//    {
//        if(it.second==1)
//        {
//            ck=1;
//
//            value = it.first;
//            if(mn>value)
//            {
//                indx = ind[value];
//                mn = value;
//            }
//
//        }
//
//    }
//    if(ck==0)
//        cout<<"-1"<<endl;
//    else
//        cout<<indx<<endl;
//}
//int main()
//{
//    ll t;
//    cin>>t;
//    while(t--)
//    {
//        solve();
//    }
//}
//void solve()
//{
//
//    ll x;
//    cin>>x;
//    ll a[5];
//    for(int i=1;i<=3;i++)
//    {
//        cin>>a[i];
//    }
//    if(a[x]!=0 && a[a[x]]!=0)
//        cout<<"YES"<<endl;
//    else
//        cout<<"NO"<<endl;
////    for(int i=0;i<s.size();i++)
////    {
////        st.insert(s[i]);
////    }
////    for(auto it:st)
////        cout<<it;
////    cout<<endl;
//}
//
//int main()
//{
//
//
//    ll t;
//    cin>>t;
//    while(t--)
//    {
//        solve();
//
//    }
//
//    return 0;
//}


//string ps;
//
//bool ispal(string s)
//{
//    for(int i=0; i<s.size()/2; i++)
//    {
//        if(s[i]!=s[s.size()-i-1])
//        {
//            return false;
//        }
//    }
//    return true;
//}
//
//void subString(string s, int n)
//{
//    for(int i=0; i<n; i++)
//    {
//        for(int len = 1; len<=n-i; len++)
//        {
//            ps = s.substr(i,len);
//            if(ispal(ps) && (ps.size()>1))
//            {
//                cout<<"NO"<<endl;
//                return;
//            }
//
//        }
//    }
//    cout<<"YES"<<endl;
//    return;
//
//
//}
//
//int main()
//{
////    string s1 = "Geeks";
////    string r = s1.substr(5,5);
////    cout<<"String is : "<<r<<endl;
//
////    string s = "dog:cat";
////    int pos = s.find(":");
////    string sub = s.substr(0,pos);
////    cout<<"String is "<<sub<<endl;
//
//    ll t;
//    cin>>t;
//    while(t--)
//    {
//        ll n;
//        cin>>n;
//        string s;
//        cin>>s;
//        subString(s,s.size());
//
//    }
//
//    return 0;
//}
