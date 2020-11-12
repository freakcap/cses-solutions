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
    cin >> n;
    ll x;
    stack<pair<ll, ll>>st;
    fo(i, 0, n) {
        cin >> x;
        if (st.empty()) {
            cout << 0 << " ";
            st.push({x, i + 1});
        }
        else {
            while (st.top().F >= x) {
                st.pop();
                if (st.empty()) break;
            }
            if (st.empty()) {
                cout << 0 << " ";
            }
            else {
                cout << st.top().S << " ";
            }
            st.push({x, i + 1});
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
    return 0;
}