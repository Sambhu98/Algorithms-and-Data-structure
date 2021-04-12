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
#define ld double
#define pb push_back
#define eb emplace_back
#define gcd(a,b) __gcd(a,b)
#define fi first
#define se second
#define endl "\n"
//check the size of the vertices  <---<---<---<---<---<---<---<-
const int N = 1e4 + 5;
vector<int> parent(N);
vector<int> s(N);
struct edges {
	int a;
	int b;
	int w;
};
bool comp(edges x, edges y)
{
	if (x.w < y.w)
		return true;

	return false;
}
void make_set(int v) {
	parent[v] = v;
	s[v] = 1;
}
int find_set(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (s[a] < s[b])
			swap(a, b);
		parent[b] = a;
		s[a] += s[b];
	}
}
void solve()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		make_set(i);

	vector<edges> ar(m);
	for (int i = 0; i < m; i++)
		cin >> ar[i].a >> ar[i].b >> ar[i].w;

	sort(all(ar), comp);
	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		if (find_set(ar[i].a) != find_set(ar[i].b))
		{
			union_sets(ar[i].a, ar[i].b);
			sum += ar[i].w;
		}
	}

	cout << sum << endl;
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
