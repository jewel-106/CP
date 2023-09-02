#include<bits/stdc++.h>
//#define ONLINE_JUDGE
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    while(n--)
    {
        int l,r;
        cin>>l>>r;
        int cnt = 0;
        while(l!=r)
        {
            if(l>r)
                l/=2;
            else
                r/=2;
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}