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
#define int ll
const int N = 3e5 + 5;
vector<int> bit(N);
void updatebit(int indx, int val)
{
	while (indx < N)
	{
		bit[indx] += val;
		//adding lowest set bit
		indx += (indx & (-indx));
	}
}
int sum(int indx)
{
	int s = 0;
	while (indx > 0)
	{
		s += bit[indx];
		//removing lowest set bit
		indx -= (indx & (-indx));
	}
	return s;
}
void solve()
{
	int n;
	cin >> n;

	vector<int> ar(n + 1);

	int invrcount = 0;
	// permutation is from 0 to n-1
	// converting it into 0 to n
	for (int i = 1; i <= n; i++)
	{	cin >> ar[i]; ++ar[i];

		updatebit(ar[i], 1);
		invrcount += (i - sum(ar[i]));
	}

	cout << invrcount << endl;
}
int32_t main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	fio
	//itc
	solve();
	return 0;
}