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
    vector<int>arr(n);
    fo(i, 0, n) cin >> arr[i];
    vector<vector<int>>dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;
    // fo(i,1,k+1) dp[0][i] = 1;
    // fo(i,1,n+1) dp[i][0] = 1;
    fo(i, 1, n + 1)
    {
        fo(j, 0, k + 1)
        {
            (dp[i][j] += dp[i - 1][j]) %= M;
            if (j - arr[i - 1] >= 0)
                (dp[i][j] += dp[i][j - arr[i - 1]]) %= M;
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