// CP
// Atharva's Code
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;

const lld pi = 3.141592653589793238;
const ll INF = LONG_LONG_MAX;
const ll mod = (int)1e9 + 7;

typedef pair<ll, ll> pl;
typedef vector<ll> vl;
typedef vector<pl> vpl;
typedef vector<string> vs;
typedef map<ll, ll> ml;
typedef unordered_map<ll, ll> uml;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define repR(i, a, b) for (ll i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define inputVec(a, n) \
    rep(i, 0, n) { cin >> a[i]; }
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
} //__gcd
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
ll moduloMultiplication(ll a, ll b, ll mod)
{
    ll res = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        b >>= 1;
    }
    return res;
}
ll powermod(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
#define setBits(x) __builtin_popcount(x)
#define arraySum(a) accumulate(a.begin(), a.end(), (ll)0);
ll binaryToDecimal(string s)
{
    return stoi(s, 0, 2);
}
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
bool isPerfectSquare(ll x)
{
    if (x >= 0)
    {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}

ll f(ll i, ll rem, vl &a, ll n,vector<vl> &dp)
{
    if (rem == 0)
    {
        return 0;
    }
    if (rem < 0)
    {
        return 1e9;
    }
    if (i >= n)
    {
        return 1e9;
    }
    if(dp[i][rem]!=-1){
        return dp[i][rem];
    }
    ll take = 1e9, notTake = f(i + 1, rem, a, n,dp);
    if (rem >= a[i])
    {
        take = 1 + min(f(i + 1, rem - a[i], a, n,dp), f(i, rem - a[i], a, n,dp));
    }
    return dp[i][rem]=min(take, notTake);
}

void solve()
{
    ll n;
    cin >> n;
    ll x;
    cin >> x;
    vl a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    vector<ll> dp(x+1,1e9);
    rep(i,0,n+1){
        dp[0]=0;
    }
    repR(i,n-1,0){
        vl curr(x+1,1e9);
        curr[0]=0;
        rep(rem,0,x+1){
            ll take=1e9,notTake=dp[rem];
            if(rem>=a[i]){
                take=1+min(curr[rem-a[i]],dp[rem-a[i]]);
            }
            curr[rem]=min(take,notTake);
        }
        dp=curr;
    }
    if(dp[x]>=1e9){
        cout<<-1<<endl;
        return;
    }
    cout<<dp[x]<<endl;
    // cout << f(0, x, a, n,dp) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
