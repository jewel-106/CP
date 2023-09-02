// C++ program to illustrate std::istringstream
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
// Driver Code
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // Input string
    string a("1 2 3 5 6 7 8 9 10 11 12 13 14 15");

    // Object class of istringstream
    string temp;
    getline(cin,temp);
    istringstream my_stream(a);

    // Variable to store number n
    int n;

    // Stream a number till white space
    // is encountered
    while(my_stream >> n)
    {
        cout << n << "\n";
    }

    // Print the number
    
}
