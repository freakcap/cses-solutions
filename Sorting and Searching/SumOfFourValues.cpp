#include<bits/stdc++.h>
#define ll          long long int
#define pb          push_back
#define F           first
#define S           second
#define vll         vector<ll>
#define mll         unordered_map<ll,ll>
#define minpq       priority_queue<ll,vector<ll>,greater<ll>>
#define maxpq       priority_queue<ll>
#define endl        "\n"
#define all(x)      x.begin(),x.end()
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
    cin >> n >> k;
    vector<ll>arr(n);
    for (auto& v : arr) cin >> v;
    vector < pair<int, pair<int, int>>>a;
    fo(i, 0, n - 1) {
        fo(j, i + 1, n) {
            a.pb({arr[i] + arr[j], {i, j}});
        }
    }
    sort(all(a));
    int i = 0, j = a.size() - 1;
    while (i < j) {
        if (a[i].F + a[j].F > k) {
            j--;
        }
        else if (a[i].F + a[j].F < k) {
            i++;
        }
        else {
            if (a[i].S.F == a[j].S.F || a[i].S.S == a[j].S.F || a[i].S.F == a[j].S.S || a[i].S.S == a[j].S.S) {
                i++;
            }
            else {
                vector<ll>ans = {a[i].S.F + 1, a[i].S.S + 1, a[j].S.F + 1, a[j].S.S + 1};
                sort(all(ans));
                for (auto& v : ans) cout << v << " ";
                return;
            }
        }
    }
    cout << "IMPOSSIBLE";
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