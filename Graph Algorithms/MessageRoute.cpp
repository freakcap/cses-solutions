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
vector<int>vis, prev1;
void bfs(int i) {
    queue<int> q;
    q.push(i);
    vis[i] = true;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto x : gp[curr]) {
            if (!vis[x]) {
                q.push(x);
                prev1[x] = curr;
                vis[x] = true;
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    gp.resize(n + 1);
    vis.resize(n + 1, false);
    prev1.resize(n + 1, -1);
    while (m--) {
        int u, v; cin >> u >> v;
        gp[u].pb(v);
        gp[v].pb(u);
    }
    bfs(1);
    if (prev1[n] == -1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<int>ans;
    ans.pb(n);
    while (prev1[n] != -1) {
        ans.pb(prev1[n]);
        n = prev1[n];
    }
    cout << ans.size() << endl;
    for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
        cout << *it << " ";
    }
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