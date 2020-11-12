#include<bits/stdc++.h>

#define ll          long long int
#define pb          push_back
#define mpP          make_pair
#define vi          vector<int>
#define vll         vector<ll>
#define mii         unordered_map<int,int>
#define mll         map<ll,ll>
#define endl        "\n"
#define debug(x)    cout<< #x <<"="<<x<<"\n"
#define fo(i,a,x)   for(ll i=a;i<x;++i)

using namespace std;


ll n, m, k;
vll arr;
mll mp;



void solve()
{
    cin >> n >> k;
    ll sum = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        sum += m;
        if (sum == k) ans++;
        if (mp.find(sum - k) != mp.end()) ans += mp[sum - k];
        mp[sum]++;
    }
    cout << ans << endl;
}

int main()
{
    ll t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}