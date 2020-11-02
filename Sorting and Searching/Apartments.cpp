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
    cin >> n >> m >> k;
    vector<int>arr(n), cap(m);
    for (auto& v : arr) cin >> v;
    for (auto& v : cap) cin >> v;
    sort(arr.begin(), arr.end());
    sort(cap.begin(), cap.end());
    int cnt = 0, j = 0, i = 0;
    while (true)
    {
        if (i >= n || j >= m) break;
        if (abs(arr[i] - cap[j]) <= k)
        {
            cnt++;
            i++;
            j++;
        }
        else if (arr[i] < cap[j])
        {
            i++;
        }
        else {
            j++;
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
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}