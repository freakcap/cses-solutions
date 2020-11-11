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
    cin >> n >> k;
    ll ans1 = -1, ans2 = -1, ans3 = -1;
    vector<ll>arr(n);
    fo(i, 0, n) {
        cin >> arr[i];
    }
    auto ind = arr;
    sort(all(arr));
    fo(i, 0, n - 2) {
        if (arr[i] >= k) break;
        fo(j, i + 1, n) {
            if (arr[i] + arr[j] >= k) break;
            auto it = lower_bound(arr.begin() + j + 1, arr.end(), k - (arr[i] + arr[j]));
            if (*it == k - (arr[i] + arr[j])) {
                ans1 = arr[i];
                ans2 = arr[j];
                ans3 = *it;
                break;
            }
        }
        if (ans1 != -1) break;
    }
    if (ans1 == -1) {
        cout << "IMPOSSIBLE";
        return;
    }
    bool flag1 = true, flag2 = true, flag3 = true;
    fo(i, 0, n) {
        if (ind[i] == ans1 && flag1) {
            cout << i + 1 << " ";
            flag1 = false;
        }
        else if (ind[i] == ans2 && flag2) {
            cout << i + 1 << " ";
            flag2 = false;
        }
        else if (ind[i] == ans3 && flag3) {
            cout << i + 1 << " ";
            flag3 =  false;
        }
        if (!flag1 && !flag2 && !flag3) return;
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