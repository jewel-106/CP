#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int ar[101],st[404];

void buildTree(int si, int ss, int se)
{
    if(ss == se)
    st[si] = ar[ss];

    int mid = (ss + se) /2;

    buildTree(2*si,ss,mid);
    buildTree(2*si+1,mid+1,se);

    st[si] = min(st[2*si],st[2*si+1]);
}


int query(int si, int ss, int se, int qs, int qe)
{
    if(ss>qe || se<qs)
    return INT_MAX;

    if(ss>=qs && se<=qe)
    return st[si];

    int mid = (ss+se)/2;
    int l = query(2*si,ss,mid,qs,qe);
    int r = query(2*si+1,mid+1,se,qs,qe);

    return min(l,r);
}
int main()
{
    int l,r,q,n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>ar[i];

    buildTree(1,1,n);

    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        cout<<query(1,1,n,l,r)<<endl;
    }
}