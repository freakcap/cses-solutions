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
    vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
    fo(i, 1, n + 1)
    {
        fo(j, 1, m + 1)
        {
            if (i == j)
            {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = M;
                fo(k, 1, i)
                {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j]);
                }
                fo(k, 1, j)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k]);
                }
                dp[i][j] += 1;
            }
        }
    }
    cout << dp[n][m];
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