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

void solve()
{
    ll sum = 0, maxx = 0;
    cin >> n >> k;
    vector<ll>arr(n);
    for (auto& v : arr) {
        cin >> v;
        maxx = max(maxx, v);
        sum += v;
    }
    ll l = maxx;
    ll r = sum;
    while (l < r) {
        ll mid = (l + r) / 2;
        ll cnt = 0, curr = 0;
        for (auto& v : arr) {
            curr += v;
            if (curr > mid) {
                curr = v;
                cnt++;
            }
        }
        cnt++;
        if (cnt <= k) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << l;
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