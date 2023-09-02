#include <bits/stdc++.h>
#define Fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Fread freopen ("input.txt","r",stdin);
#define Fout freopen ("output.txt","w",stdout);
using namespace std;


#define ll long long int

int ar[1001],st[4004];
/// ss = segment start,se = segment end, si = segment index
void buildTree(int si, int ss, int se)
{
    if(ss==se)
    {
        st[si] = ar[ss];
        return;
    }

    int mid = (ss+se)/2;

    buildTree(2*si, ss, mid);
    buildTree(2*si+1,mid+1,se);

    st[si] = min(st[2*si],st[2*si+1]);
}

/// Answering the query
/// qs = query start and qe = query end

int query(int si, int ss, int se, int qs , int qe)
{
    if (ss > qe  || se < qs) /// completly outside
    return INT_MAX;

    if(ss>=qs && se<=qe)/// completly inside
    return st[si];

    int mid = (ss+se)/2;
    int l = query(2*si,ss,mid,qs,qe);
    int r = query(2*si+1,mid+1,se,qs,qe);

    return min(l,r);
}
void update(int si, int ss, int se, int qi)
{
    if (ss == se)
    {
    st[si] = ar[ss];
    return;
    }

    int mid = (ss + se) / 2;
    if (qi <= mid)
    update(2 * si, ss, mid, qi);
    else
    update(2 * si + 1, mid + 1, se, qi);

    st[si] = min(st[2 * si], st[2 * si + 1]);
}

int main()
{
    Fast
    #ifndef ONLINE_JUDGE
        Fread
        Fout
    #endif
    ll t=1;
    //cin>>t;
    while(t--)
    {
        int n,q,l,r;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>ar[i];

        buildTree(1,1,n);
        cin>>q;

        while(q--)
        {
            cin>>l>>r;
            cout<<query(1,1,n,l+1,r+1)<<endl;
        }
    }
    
    return 0;
}
