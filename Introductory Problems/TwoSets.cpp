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
    cin >> n;
    ll sum = n * (n + 1) / 4;
    if (n * (n + 1) % 4)
    {
        cout << "NO";
        return;
    }
    set<ll> f1, s2;
    for (ll i = n; i > 0; i--)
    {
        if (sum - i >= 0)
        {
            sum -= i;
            f1.insert(i);
        }
        else {
            s2.insert(i);
        }
    }
    if (sum == 0)
    {
        cout << "YES\n";
        cout << f1.size() << endl;
        for (auto& x : f1) cout << x << " ";
        cout << endl;
        cout << s2.size() << endl;
        for (auto& x : s2) cout << x << " ";
        return;
    }
    else {
        cout << "NO";
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