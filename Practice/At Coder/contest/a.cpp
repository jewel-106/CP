#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
   string s;
   cin>>s;
   int n = s.size();
   string d="";
   int cnts=0;
   int cntb= 0;
   for(int i=0;i<s.size();i--)
   {
        if(s[i]>='a' && s[i]<='z')
            cnts++;
        if(s[i]>='A' && s[i]<='Z')
            cntb++;
        if(s[i]>='0' && s[i]<='9')
            d=d+s[i];
   }
   int num = stoi(d);
   if (cnts == 1 && cntb == 1 && (num >= 100000 && num <= 999999))
        cout << "Yes" << endl;
   else
        cout << "No" << endl;
}
