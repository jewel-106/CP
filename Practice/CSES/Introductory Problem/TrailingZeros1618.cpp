

#include<bits/stdc++.h>
using namespace std;
void fact(int n)
{
    int s=0,m=5;
    while(n>=m)
    {
        s+=n/m;
        m*=5;
    }
    cout<<s<<endl;
}
int main()
{
    int n;
    cin>>n;
    fact(n);
}
