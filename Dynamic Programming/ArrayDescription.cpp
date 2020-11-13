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
    cin >> n >> m;
    vector<ll>arr(n);
    for (auto& v : arr) cin >> v;
    vector<vector<ll>>dp(n + 1, vector<ll>(m + 2, 0));
    if (arr[0] == 0)
    {
        fo(i, 1, m + 1) dp[0][i] = 1;
    }
    else dp[0][arr[0]] = 1;
    fo(i, 1, n + 1)
    {
        if (arr[i] == 0)
            fo(v, 1, m + 1)
        {
            dp[i][v] = modAdd(dp[i - 1][v - 1], modAdd(dp[i - 1][v], dp[i - 1][v + 1]));
        }
        else dp[i][arr[i]] = modAdd(dp[i - 1][arr[i] - 1], modAdd(dp[i - 1][arr[i]], dp[i - 1][arr[i] + 1]));
    }
    ll ans = 0;
    for (ll i = 0; i < m + 1; i++) (ans += dp[n - 1][i]) %= M;
    cout << ans;
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