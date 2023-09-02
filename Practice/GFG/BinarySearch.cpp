#include <iostream>
using namespace std;

int binary_search_iterative(int A[], int x, int n)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + ((high - low) / 2);
        if (A[mid] == x)
        {
            return mid;
        }
        else if (x < A[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}
int main()
{
    int n;
    cin>>n;
    int x;
    cin>>x;
    int arr[n+5];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int ind = binary_search_iterative(arr,x,n);
    int ind2 = ind+1;
    int ind3= ind-1;
    int cnt1=0;
    int cnt2  = 0;
    if(ind!=-1)
    {
        while(arr[ind2]==x)
        {
            cnt1++;
            ind2++;
        }
        while(arr[ind3]==x)
        {
            cnt2++;
            ind3--;
        }
        cout<<cnt1<<endl;
        cout<<cnt2<<endl;
        cout<<ind-cnt2<<" "<<ind+cnt1<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }


    return 0;
}
