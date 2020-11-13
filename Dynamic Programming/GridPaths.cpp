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

bool possible(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < n);
}

void solve()
{
    cin >> n;
    string s;
    vector<vector<int>>dp(n, vector<int>(n));
    fo(i, 0, n)
    {
        cin >> s;
        fo(j, 0, n)
        {
            dp[i][j] = (s[j] == '.') ? 0 : -1;
        }
    }
    if (dp[0][0] == -1 || dp[n - 1][n - 1] == -1)
    {
        cout << 0;
        return;
    }
    dp[0][0] = 1;
    fo(i, 0, n)
    {
        fo(j, 0, n)
        {
            if (dp[i][j] == -1)continue;
            if (possible(i, j - 1))
            {
                if (dp[i][j - 1] != -1)
                {
                    (dp[i][j] += dp[i][j - 1]) %= M;
                }
            }
            if (possible(i - 1, j))
            {
                if (dp[i - 1][j] != -1)
                {
                    (dp[i][j] += dp[i - 1][j]) %= M;
                }
            }
        }
    }
    if (dp[n - 1][n - 1] == -1) dp[n - 1][n - 1] = 0;
    cout << dp[n - 1][n - 1];
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