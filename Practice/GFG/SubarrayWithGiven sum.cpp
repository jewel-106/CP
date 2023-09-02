#include<bits/stdc++.h>
#define ll long long int

using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+5];
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            int a = arr[i];
            if(a&1)
                cnt++;
        }
        cout<<cnt<<endl;


    }
    return 0;
}
