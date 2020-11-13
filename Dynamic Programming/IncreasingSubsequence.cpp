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
void onlineJ() {freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);}

ll n, m, k;
const ll M = (ll)1e9 + 7;

void solve()
{
    cin >> n;
    vector<ll>arr;
    int x;
    fo(i, 0, n)
    {
        cin >> x;
        auto it = lower_bound(arr.begin(), arr.end(), x);
        if (it == arr.end())
        {
            arr.pb(x);
        }
        else
        {
            *it = x;
        }
    }
    cout << arr.size();

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