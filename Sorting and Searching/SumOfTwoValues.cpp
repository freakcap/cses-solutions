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
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
void onlineJ() {freopen("input.txt", "r", stdin); freopen("error.txt", "w", stderr); freopen("output.txt", "w", stdout);}

ll n, m, k;
const ll M = (ll)1e9 + 7;

void solve()
{
    cin >> n >> k;
    vector<ll>arr(n), trash;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        if (!(k & 1) && arr[i] == k / 2) trash.push_back(i + 1);
    }
    if (trash.size() >= 2)
    {
        cout << trash[0] << " " << trash[1];
        return;
    }
    ll a = -1, b = -1;
    set<ll>opt;
    for (auto& x : arr) opt.insert(x);
    for (auto q : opt)
    {
        if ((!(k & 1) && q == k / 2) || q >= k) continue;
        ll x = k - q;
        if (opt.find(x) != opt.end())
        {
            a = q;
            b = x;
            break;
        }
        else continue;
    }
    if (a != b)
    {
        for (ll i = 0; i < n; i++)
        {
            if (arr[i] == a)
            {
                cout << i + 1 << " ";
                a = -1;
            }
            else if (arr[i] == b)
            {
                cout << i + 1 << " ";
                b = -1;
            }
            if (a == -1 && b == -1) break;
        }
        return;
    }
    else {
        cout << "IMPOSSIBLE";
    }
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