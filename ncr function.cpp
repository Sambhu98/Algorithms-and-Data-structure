/*Author -> SAMBHU SHOW
Jalpaiguri Govt. Engineering College */
#include<bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define itc ll t;cin>>t;while(t--)
#define PI 3.141592653589793238
#define Max(a,b,c) max(a,max(b,c));
#define Min(a,b,c) min(a,min(b,c));
#define all(v) v.begin(),v.end()
#define revall(v) v.rebegin(),v.rend()
#define ll long long int
#define ld long double
#define pb push_back
#define eb emplace_back
#define gcd(a,b) __gcd(a,b)
#define fi first
#define se second
#define endl "\n"
ll mod = 1e9 + 7;
ll add(ll a, ll b)
{ll val = (a % mod + b % mod) % mod; return val;}
ll sub(ll a, ll b)
{ll val = ((a % mod - b % mod) + mod) % mod; return val;}
ll mult(ll a, ll b)
{ll val = ((a % mod) * (b % mod)) % mod; return val;}
const ll N = 1e6 + 10;
vector<ll> fact(N), inver(N);
ll powm(ll x, ll n)
{
    ll result = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
            result = (result * x) % mod;
        x = (x * x) % mod;
        n = n / 2;
    }
    return result;
}
void precal()
{
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
        fact[i] = mult(fact[i - 1], i);


    inver[N - 1] = powm(fact[N - 1], mod - 2);
    for (ll i = N - 2; i >= 0; i--)
    {
        inver[i] = mult(inver[i + 1], i + 1);
    }
}
ll ncr(ll a, ll b)
{
    ll ans = fact[a];
    ans = mult(ans, inver[a - b]);
    ans = mult(ans, inver[b]);

    return ans;
}
void solve()
{

}
int main()
{
// #ifndef ONLINE_JUDGE
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
// #endif
    fio
    precal();
    //itc
    solve();
    return 0;
}