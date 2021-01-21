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
#define ll long long int
#define ld long double
#define pb push_back
#define eb emplace_back
#define gcd(a,b) __gcd(a,b)
#define fi first
#define se second
#define endl "\n"
const int N = 1e6 + 5;
vector<bool> prime;
void SieveOfEratosthenes()
{
	for (ll i = 0; i < N; i++)
		prime.pb(1);

	for (int p = 2; p * p <= N; p++)
	{
		if (prime[p] == true)
		{
			for (int i = p * p; i <= N; i += p)
				prime[i] = false;
		}
	}
}
void solve()
{
	SieveOfEratosthenes();
}
int main()
{
// #ifndef ONLINE_JUDGE
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
// #endif
	fio
	//itc
	solve();
	return 0;
}