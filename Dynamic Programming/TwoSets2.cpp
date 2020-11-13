#include<bits/stdc++.h>
#define ll          long long int
#define pb          push_back
#define vll         vector<ll>
#define mll         unordered_map<ll,ll>
#define minpq       priority_queue<ll,vector<ll>,greater<ll>>
#define maxpq       priority_queue<ll>
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
    ll sum = n * (n + 1) / 2;
    if (sum & 1)
    {
        cout << 0;
        return;
    }
    sum /= 2;
    vector<vector<int>>dp(n + 1, vector<int>(sum + 1, 0));
    dp[0][0] = 1;
    fo(i, 1, n + 1)
    {
        fo(j, 1, sum + 1)
        {
            dp[i][j] = dp[i - 1][j] ;
            if (j - i >= 0)
                (dp[i][j] += dp[i - 1][j - i]) %= M;
        }
    }
    cout << dp[n][sum];
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