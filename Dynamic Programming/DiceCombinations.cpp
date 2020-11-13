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
    vector<int>dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    fo(i, 2, n + 1)
    {
        ll sum = 0;
        ll x = 1;
        while (x <= 6 && x < i)
        {
            sum = modAdd(dp[i - x], sum);
            x++;
        }
        if (i <= 6) sum++;
        dp[i] = sum;
    }
    cout << dp[n] % M;
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