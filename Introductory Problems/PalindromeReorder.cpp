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
    string s; cin >> s;
    int arr[26] = {0};
    for (auto& c : s) arr[c - 'A']++;
    int cnt = 0;
    char c = '-';
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] & 1)
        {
            cnt++;
            c = i + 'A';
            arr[i] = (arr[i] - 1) / 2 + 1;
        }
        else arr[i] /= 2;
    }
    if (cnt > 1)
    {
        cout << "NO SOLUTION";
        return ;
    }
    string ans = "";
    for (int i = 0; i < 26; i++)
    {
        if (c == i + 'A') arr[i]--;
        for (int j = 0; j < arr[i]; j++)
        {
            ans.push_back(i + 'A');
        }
    }
    string rev = ans;
    reverse(rev.begin(), rev.end());
    if (c != '-') ans.push_back(c);
    ans += rev;
    cout << ans;
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