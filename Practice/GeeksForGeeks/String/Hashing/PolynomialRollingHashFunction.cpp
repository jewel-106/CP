#include <bits/stdc++.h>
using namespace std;

ll power(ll x, ll y, ll p)
{
    ll result = 1;
    for(; y; y>>=1,x=x*x%p)
    {
        if(y&1)
        {
            result = result *x % p;
        }
    }
    return result;
}

ll inverse(ll x, ll p)
{
    return power(x,p-2,p);
}

class Hash
{
private:
    int length;
    const int mod1 = 1e9+7,mod2 = 1e9+9;
    const int p1 = 31,p2 = 37;
    vector<int> hash1,hash2;
    pair<int,int> hash_pair;

public:
    inline static vector<int> inv_pow1,inv_pow2;
    inline static int inv_size = 1;

    Hash() {}

    Hash(const string& s)
    {
        length = s.size();
        hash1.resize(length);
        hash2.resize(length);

        int h1=0,h2=0;
        ll p_pow1 = 1,p_pow2 = 1;
        for(int i=0; i<length; i++)
        {
            h1 = (h1+ (s[i] - 'a' +1) *p_pow)%mod1;
            h2 = (h2 + (s[i] - 'a' +1) * p_pow)%mod2;
            p_pow1 = (p_pow1*p1)%mod1;
            p_pow2 = (p_pow2*p2)%mod2;
            hash1[i] = h1;
            hash2[i] = h2;
        }
        hash_pair = make_pair(h1,h2);

        if(inv_size<length)
        {
            for(; inv_size<length; inv_size<<=1);

            inv_pow1.resize(inv_size,-1);
            inv_pow2.resize(inv_size,-1);

            inv_pow1[inv_size - 1] = inverse(power(p1,inv_size -1, mod1), mod1);
            inv_pow2[inv_size - 1] = inverse(power(p2,inv_size -1, mod2), mod2);

            for(int i=inv_size-2; i>=0 && inv_pow1[i]==-1; i--)
            {
                inv_pow1[i] = (1LL * inv_pow1[i+1]*p1)%mod1;
                inv_pow2[i] = (1LL * inv_pow2[i+1]*p2)%mod2;
            }
        }
    }

    int size()
    {
        return length;
    }

    pair<int,int> prefix(const int index)
    {
        return {hash1[index],hash2[index]};
    }

    pair<int,int> substr(const int l, const int r)
    {
        if(l==0)
        {
            return {hash1[r],hash2[r]};
        }
        int temp1 = hash1[r]-hash1[l-1];
        int tmep2 = hash2[r] - hash2[l-1];
        temp1 += (temp1<0?mod1:0);
        temp2 += (temp2<0?mod2:0);
        temp1 = (temp1 *1LL * inv_pow1[l]) % mod1;
        temp2 = (temp2 *1LL * inv_pow2[l]) % mod2;
        return {temp1,temp2};
    }
    bool operator==(conast Hash& other)
    {
        return (hash_pair == other.hash_pair);
    }
};

void query(vector<Hash>& hashes, const int N)
{
    int i=0,j=0;
    cin>>i>>j;
    i--,j--;
    int lb = 0,ub = min(hashes[i].size(),hashes[j].size());
    int max_length = 0;
    while(lb<=ub)
    {
        int mid = (lb+ub)>>1;
        if(hashes[i].prefix(mid) == hashes[j].prefix(mid))
        {
            if(mid + 1> max_length)
            {
                max_length = mid +1;
            }
            lb = mid +1;
        }
        else
        {
            ub = mid - 1;
        }
    }
    cout<<max_length<<endl;
}


int main()
{
    int N = 0,Q=0;
    cin>>N>>Q;
    vector<Hash> hashes;
    for(int i=0; i<N; i++)
    {
        string s;
        cin>>s;
        hashes.push_back(Hash(s));
    }
    for(; Q>0; Q--)
    {
        query(hashes,N);
    }
    return 0;
}
//ll power(ll x, ll y, ll p)
//{
//    ll result = 1;
//    for(; y; y >>= 1, x = x * x % p)
//    {
//        if(y&1)
//        {
//            result = result * x % p;
//        }
//    }
//    return result;
//}
//
//ll inverse(ll x, ll p)
//{
//    return power(x,p-2,p);
//}
//
//class Hash
//{
//private:
//    int length;
//    const int mod1 = 1e9 + 7, mod2 = 1e9+9;
//    const int p1 = 31, p2 = 37;
//    vector<int> hash1,hash2;
//    pair<int,int>hash_pair;
//
//public:
//    inline static vector<int> inv_pow1,inv_pow2;
//    inline static int inv_size = 1;
//
//    Hash() {}
//    Hash(const string& s)
//    {
//        length = s.size();
//        hash1.resize(length);
//        hash2.resize(length);
//
//        int h1 = 0,h2 = 0;
//        ll p_pow1 = 1, p_pow2 = 1;
//        for(int i=0; i<length; i++)
//        {
//            h1 = (h1 + (s[i] - 'a' + 1) * p_pow1) % mod1;
//            h2 = (h2 + (s[i] - 'a' + 1) * p_pow2)%mod2;
//            p_pow1 = (p_pow1*p1) % mod1;
//            p_pow2 = (p_pow2*p2) % mod2;
//            hash1[i] = h1;
//            hash2[i] = h2;
//        }
//        hash_pair = make_pair(h1,h2);
//
//        if(inv_size<length)
//        {
//            for(; inv_size<length; inv_size <<= 1);
//            inv_pow1.resize(inv_size,-1);
//            inv_pow2.resize(inv_size,-1);
//            inv_pow1[inv_size-1] = inverse(power(p1,inv_size-1,mod1),mod1);
//            inv_pow2[inv_size-1] = inverse(power(p2,inv_size-1,mod2),mod2);
//
//            for(int i = inv_size-2; i >=0 && inv_pow1[i] == -1; i--)
//            {
//                inv_pow1[i] = (1LL * inv_pow1[i+1]*p1)%mod1;
//                inv_pow2[i] = (1LL * inv_pow2[i+1]*p2)%mod2;
//            }
//        }
//    }
//
//    int size()
//    {
//        return length;
//    }
//    pair<int,int> prefix(const int index)
//    {
//        return {hash1[index],hash2[index]};
//    }
//
//    pair<int,int> substr(const int l,const int r)
//    {
//        if(l==0)
//        {
//            return {hash1[r],hash2[r]};
//        }
//        int temp1 = hash1[r] - hash1[l-1];
//        int temp2 = hash2[r] - hash2[l-1];
//        temp1 += (temp1<0 ? mod1:0);
//        temp2 += (temp2<0 ? mod2:0);
//        temp1  = (temp1 * 1LL * inv_pow1[l]) % mod1;
//        temp2  = (temp2 * 1LL * inv_pow2[l]) % mod2;
//        return {temp1,temp2};
//    }
//    bool operator==(const Hash& other)
//    {
//        return (hash_pair == other.hash_pair);
//    }
//
//};
//
//int main()
//{
//    string my_str = "geeksforgeeks";
//    const int n = my_str.length();
//    auto hash = Hash(my_str);
//    auto hash_pair = hash.substr(0,n-1);
//    cout<<"Hashes of the string "<<my_str<<" are: \n";
//    cout<<hash_pair.first<<' '<<hash_pair.second<<endl;
//    return 0;
//}
//struct Hash
//{
//    const int p1 = 31,m1 = 1e9+7;
//    const int p2 = 37, m2 = 1e9+9;
//    int hash1=0,hash2=0;
//    Hash(const string& s)
//    {
//        compute_hash1(s);
//        compute_hash2(s);
//    }
//    void compute_hash1(const string& s)
//    {
//        ll p_pow = 1;
//        for(char ch:s)
//        {
//            hash1 = (hash1 + (ch+1 - 'a')*p_pow)%m1;
//            p_pow = (p_pow*p1)%m1;
//        }
//    }
//    void compute_hash2(const string& s)
//    {
//        ll p_pow = 1;
//        for(char ch:s)
//        {
//            hash2 = (hash2 + (ch+1 -'a') * p_pow) %m2;
//            p_pow = (p_pow*p2)%m2;
//        }
//    }
//
//    /// For two strings to be equal
//    /// they must have same hash1 and hash2
//    bool operator==(const Hash& other)
//    {
//        return (hash1 == other.hash1 && hash2 == other.hash2);
//    }
//
//};
//
//int main()
//{
//    const string s = "geeksforgeeks";
//    Hash h(s);
//    cout<<"Hash value of "<<s<<" are: ";
//    cout<<"("<<h.hash1<<", "<<h.hash2<<")"<<endl;
//}
/// c++ code
//struct Hash
//{
//    ll p = 31,m = 1e9+7;
//    ll hash_value;
//    Hash(const string& s)
//    {
//        ll hash_so_far = 0;
//        ll p_pow = 1;
//        const ll n = s.size();
//        for(ll i=0; i<n; ++i)
//        {
//            hash_so_far  = (hash_so_far + (s[i] - 'a' +1) *p_pow) %m;
//            p_pow  = (p_pow*p)%m;
//        }
//        hash_value = hash_so_far;
//    }
////    bool operator==(const Hash& other)
////    {
////        return (hash_value ==  other.hash_value);
////    }
//};
//int main()
//{
//    const string s = "answer";
//    Hash h(s);
//    cout<<"Hash of "<<s<<" is : "<<h.hash_value<<endl;
//
//    const string s1 = "stead";
//    Hash g(s);
//    cout<<"Hash of "<<s<<" is : "<<g.hash_value<<endl;
//
//
//    return 0;
//}

/// c code
//int get_hash(const char* s, const int n)
//{
//    ll p = 31, m = 1e9+7;
//    ll Hash = 0;
//    ll p_pow = 1;
//    for(int i=0;i<n;i++)
//    {
//        Hash = (Hash + (s[i]-'a' +1)*p_pow) % m;
//        p_pow = (p_pow*p)%m;
//    }
//    return Hash;
//
//
//}
//
//int main()
//{
//    char s[] = "geeksforgeeks";
//    int n =strlen(s);
//    printf("Hash of %s is %d\n",s,get_hash(s,n));
//    return 0;
//}
//const ll limit = 1e6+5;
//const ll Mod = 1e9+7;
//
//void solve()
//{
//
//}
//
//int main()
//{
//    Fast
//    #ifndef ONLINE_JUDGE
//        Fread
//        Fout
//    #endif
//    ll t=1;
//    //cin>>t;
//    while(t--)
//    {
//        solve();
//    }
//
//    return 0;
//}
