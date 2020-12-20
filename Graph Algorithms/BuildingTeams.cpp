#include<bits/stdc++.h>
#define ll          long long int
#define pb          push_back
#define F           first
#define S           second
#define vll         vector<ll>
#define mll         map<ll,ll>
#define minpq       priority_queue<ll,vector<ll>,greater<ll>>
#define maxpq       priority_queue<ll>
#define endl        "\n"
#define modAdd(a,b) ((a%M)+(b%M))%M
#define modMul(a,b) ((a%M)*(b%M))%M
#define all(x)      x.begin(),x.end()
#define debug(x)    cout<< #x <<"="<<x<<"\n"
#define fo(i,a,x)   for(ll i=a;i<x;++i)
#define fastio      ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
void onlineJ() {freopen("input.txt", "r", stdin); freopen("error.txt", "w", stderr); freopen("output.txt", "w", stdout);}

ll n, m, k;
const ll M = (ll)1e9 + 7;
vector<vector<int>>gp;
vector<int>vis, ans;
bool flag = true;
void dfs(int i, int par = -1) {
    vis[i] = true;
    if (par == -1) {
        ans[i] = 1;
    }
    else {
        if (ans[par] == 1) ans[i] = 2;
        else ans[i] = 1;
    }
    for (auto x : gp[i]) {
        if (!vis[x]) {
            dfs(x, i);
        }
        if (ans[x] == ans[i]) {
            flag = false;
        }
    }
}
void solve()
{
    cin >> n >> m;
    gp.resize(n + 1);
    vis.resize(n + 1, false);
    ans.resize(n + 1, 0);
    while (m--) {
        int u, v; cin >> u >> v;
        gp[u].pb(v);
        gp[v].pb(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    ans.erase(ans.begin());
    if (!flag) cout << "IMPOSSIBLE";
    else for (auto x : ans) cout << x << " ";
    cout << endl;
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
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}