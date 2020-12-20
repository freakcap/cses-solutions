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
vector<string>gp;
vector<vector<bool>>vis;
vector<vector<int>>dist;
vector<int>drx = {1, -1, 0, 0}, dry = {0, 0, 1, -1};
vector<char>path = {'U', 'D', 'L', 'R'};
bool isValid(pair<int, int> node) { return (node.F < n && node.F >= 0 && node.S < m && node.S >= 0);}
void bfs(pair<int, int>start, pair<int, int> target) {
    queue<pair<int, int>>q;
    q.push(start);
    vis[start.F][start.S] = true;
    dist[start.F][start.S] = 1;
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        if (curr == target) return;
        for (int i = 0; i < 4; i++) {
            pair<int, int> tmp = {curr.F + drx[i], curr.S + dry[i]};
            if (!isValid(tmp) || vis[tmp.F][tmp.S]) continue;
            q.push(tmp);
            vis[tmp.F][tmp.S] = true;
            dist[tmp.F][tmp.S] = dist[curr.F][curr.S] + 1;
        }
    }
}
void printAns(pair<int, int> target) {
    if (dist[target.F][target.S] <= 1) {
        cout << "NO" << endl;
        return;
    }
    string ans = "";
    cout << "YES" << endl;
    cout << dist[target.F][target.S] - 1 << endl;
    pair<int, int> curr = target;
    while (dist[curr.F][curr.S] != 1) {
        for (int i = 0; i < 4; i++) {
            pair<int, int> tmp = {curr.F + drx[i], curr.S + dry[i]};
            if (!isValid(tmp) || dist[tmp.F][tmp.S] != dist[curr.F][curr.S] - 1) continue;
            curr = tmp;
            ans.pb(path[i]);
            break;
        }
    }
    reverse(all(ans));
    cout << ans << endl;
}
void solve()
{
    cin >> n >> m;
    gp.resize(n);
    dist.resize(n, vector<int>(m, 0));
    vis.resize(n, vector<bool>(m, false));
    pair<int, int> start, target;
    for (auto& v : gp) cin >> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (gp[i][j] == '#') vis[i][j] = true;
            if (gp[i][j] == 'A') start = {i, j};
            if (gp[i][j] == 'B') target = {i, j};
        }
    }
    bfs(start, target);
    printAns(target);
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