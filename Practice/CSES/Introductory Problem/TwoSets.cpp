#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n+5];

    for(int i=1; i<=n; i++) arr[i] = i;

    int sum = (n*(n+1))/2;

    if(!(sum&1))
    {
        if(n&1)
        {
            int first = n/2;
            int second = n-first;

            cout<<"YES"<<endl;
            cout<<first<<endl;
            for(int i=1; i<=first/2; i++)
            {
                cout<<arr[i]<<" ";
            }
            for(int j=n; j>=n-first/2; j--)
            {
                cout<<arr[j]<<" ";
            }
            cout<<endl;
            cout<<second<<endl;
            for(int i = first/2+1; i<n-first/2; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;

        }


        if(!(n&1))
        {
            int first = n/2;
            int second = n/2;
            cout<<"YES"<<endl;
            cout<<first<<endl;

            for(int i=1; i<=first/2; i++)
            {
                cout<<arr[i]<<" ";
            }

            for(int j=n; j>=n-first/2+1; j--)
            {
                cout<<arr[j]<<" ";
            }
            cout<<endl;

            cout<<second<<endl;
            for(int i = first/2+1; i<n-first/2+1; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }

    else
        cout<<"NO"<<endl;
}
