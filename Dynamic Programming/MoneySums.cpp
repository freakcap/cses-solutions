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
    cin >> n;
    vector<int>arr(n);
    for (auto& v : arr) cin >> v;
    vector<vector<bool>>dp(n + 1, vector<bool>(1000 * n + 1, false));
    fo(i, 1, n + 1)
    {
        fo(j, 1, dp[i].size())
        {
            if (arr[i - 1] == j)
            {
                dp[i][j] = true;
            }
            if (dp[i - 1][j] == true)
            {
                dp[i][j] = true;
                if (arr[i - 1] + j < dp[i].size())
                    dp[i][arr[i - 1] + j] = true;
            }
        }
    }
    vector<int>ans;
    fo(i, 1, dp[n].size())
    {
        if (dp[n][i])
        {
            ans.pb(i);
        }
    }
    cout << ans.size() << endl;
    for (auto& v : ans) cout << v << " ";
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