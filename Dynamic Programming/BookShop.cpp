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
    vector<int>prices(n);
    vector<int>pages(n);
    fo(i, 0, n) cin >> prices[i];
    fo(i, 0, n) cin >> pages[i];
    vector<vector<int>>dp(n + 1, vector<int>(k + 1));
    fo(i, 0, n + 1)dp[i][0] = 0;
    fo(i, 0, k + 1)dp[0][i] = 0;
    fo(i, 1, n + 1)
    {
        fo(j, 0, k + 1)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - prices[i - 1] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - prices[i - 1]] + pages[i - 1]);
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }
    cout << dp[n][k];
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