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

bool possible(ll i, ll j)
{
    return (i < n && i >= 0 && j < m && j >= 0);
}

vector<ll>dx = {0, 0, 1, -1};
vector<ll>dy = {1, -1, 0, 0};

void dfs(ll i, ll j, vector<string>& arr)
{
    arr[i][j] = '#';
    fo(ind, 0, 4)
    {
        ll x = i + dx[ind];
        ll y = j + dy[ind];
        if (possible(x, y) && arr[x][y] == '.')
        {
            dfs(x, y, arr);
        }
    }
}

void solve()
{
    cin >> n >> m;
    string s;
    vector<string>arr(n);
    fo(i, 0, n)
    {
        cin >> arr[i];
    }
    ll cnt(0);
    fo(i, 0, n)
    {
        fo(j, 0, m)
        {
            if (arr[i][j] == '.')
            {
                dfs(i, j, arr);
                cnt++;
            }
        }
    }
    cout << cnt;
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