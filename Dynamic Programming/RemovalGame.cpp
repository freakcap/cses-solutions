#include<bits/stdc++.h>
#define ll          long long int
#define pb          push_back
#define vll         vector<ll>
#define mll         unordered_map<ll,ll>
#define endl        "\n"
#define modAdd(a,b) ((a%M)+(b%M))%M
#define modMul(a,b) ((a%M)*(b%M))%M
#define debug(x)    cout<< #x <<"="<<x<<"\n"
#define fo(i,a,x)   for(ll i=a;i<x;++i)
#define fastio      ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
void onlineJ() {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}

ll n, m, k;
const ll M = (ll)1e9 + 7;
vector<vector<ll>>dp;
ll help(vector<ll>& arr, ll l, ll r)
{
    if (dp[l][r] != -1) return dp[l][r];
    if (l == r) return dp[l][r] = arr[l];
    return dp[l][r] = max(arr[l] - help(arr, l + 1, r), arr[r] - help(arr, l, r - 1));
}

void solve()
{
    cin >> n;
    vector<ll>arr(n);
    dp.resize(n, vector<ll>(n, -1));
    for (auto& v : arr) cin >> v;
    ll sum = 0;
    for (auto&v : arr) sum += v;
    cout << (help(arr, 0, n - 1) + sum) / 2;
}

int main()
{
    fastio;
    // onlineJ();
    ll t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}