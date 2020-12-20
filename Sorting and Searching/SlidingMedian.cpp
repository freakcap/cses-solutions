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
multiset<ll, greater<ll>> pq1;
multiset<ll> pq2;

ll getmedian() {
    if (pq1.size() == pq2.size()) {
        return *pq1.begin();
    }
    else {
        if (pq1.size() > pq2.size()) {
            return *pq1.begin();
        }
        else {
            return *pq2.begin();
        }
    }
}

void balance() {
    if (pq1.size() == pq2.size()) return;
    while (pq1.size() > pq2.size()) {
        pq2.insert(*pq1.begin());
        pq1.erase(pq1.begin());
    }
    while (abs((ll)pq2.size() - (ll)pq1.size()) > 1) {
        pq1.insert(*pq2.begin());
        pq2.erase(pq2.begin());
    }
}

void insert(ll num) {
    if (pq1.size() == 0) {
        pq1.insert(num);
        return;
    }
    if (num <= *pq1.begin()) {
        pq1.insert(num);
    }
    else {
        pq2.insert(num);
    }
    balance();
}

void remove(ll num) {
    if (pq1.find(num) != pq1.end()) {
        pq1.erase(pq1.find(num));
    }
    else {
        pq2.erase(pq2.find(num));
    }
    balance();
}

void solve()
{
    cin >> n >> k;
    vector<ll>arr(n);
    for (auto& v : arr) cin >> v;
    if (k == 1) {
        for (auto& v : arr) cout << v << " ";
        return;
    }
    fo(i, 0, n) {
        insert(arr[i]);
        if (i == k - 1) {
            cout << getmedian() << " ";
        }
        if (i - k >= 0) {
            remove(arr[i - k]);
            cout << getmedian() << " ";
        }
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