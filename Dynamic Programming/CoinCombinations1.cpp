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

void solve()
{
    cin >> n >> k;
    vector<int>dp(k + 1, M);
    vector<int>arr(n);
    for (auto& x : arr) cin >> x;
    dp[0] = 1;
    for (int i = 1; i <= k; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i - arr[j] >= 0)
                (dp[i] += dp[i - arr[j]]) %= M;
        }
    }
    if (dp[k] == M) dp[k] = 0;
    cout << dp[k];
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