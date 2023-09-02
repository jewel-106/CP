

/// Minimum Swaps To Sort........

// C++ program to find
// minumum number of swaps
// required to sort an array

/*#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// Fuction returns the
// minimum number of swaps
// required to sort the array

int minSwaps(int arr[], int n)
{
    // Create an array of
    // pairs where first
    // element is array element
    // and second element
    // is position of first element
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }

    // sort the array by array
    // element values to
    // get right position of
    // every element as second
    // element of pair.
    sort(arrPos, arrPos + n);

    // To keep track of visited elements.
    // Initialize
    // all elements as not visited or false
    vector<bool> vis(n, false);

    // Initialize result
    int ans = 0;

    // Traverse array elements
    for (int i = 0; i < n; i++)
    {
        // Already swapped and correct or
        // Already present at correct pos
        if (vis[i] || arrPos[i].second == i)
            continue;

        // find out the number of node in
        // this cycle and add in ans
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;

            // move to next node
            j = arrPos[j].second;
            cycle_size++;
        }

        // Updating answer by adding current cycle
        if (cycle_size > 0)
        {
            ans += (cycle_size - 1);
        }
    }

    // Return result
    return ans;
}

// Driver code
int main()
{
    freopen("input.txt", "r",stdin);
    freopen("output.txt","w",stdout);
    // int arr[] = {1,5,4,3,2};
    // int n = (sizeof(arr) / sizeof(int));
    // cout<<minSwaps(arr,n);
    int n;
    cin >> n;
    int arr[n + 5];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << minSwaps(arr, n);
    cout << endl;

    return 0;
} */

/// Minimum Swaps To Sort........

// C++ program to find
// minumum number of swaps
// required to sort an array
// using map 
#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int minSwaps(int nums[],int n)
{
    int len = n;
    map<int,int> mp;
    for(int i=0; i<len;i++)
    {
        mp[nums[i]] = i;
    }
    sort(nums,nums+n);

    bool vis[len] = {0};

    int ans = 0;
    for(int i=0;i<len;i++)
    {
        if(vis[i] || mp[nums[i]] == i)
            continue;
        int j =i,cycle_size = 0;
        while(!vis[j])
        {
            vis[j] = true;

            j = mp[nums[j]];
            cycle_size++;
        }

        if(cycle_size>0)
        {
            ans+=(cycle_size -1);
        }
    }
    return ans;

}

int main()
{
    //int a[] = {1,5,4,3,2};
    //int n = 5;
    //cout << minSwaps(a, n) << endl;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // int arr[] = {1,5,4,3,2};
    // int n = (sizeof(arr) / sizeof(int));
    // cout<<minSwaps(arr,n);

    int n;
    cin >> n;
    int arr[n + 5];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<minSwaps(arr,n)<<endl;
    
}