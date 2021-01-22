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
void solve()
{
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> adj[n + 1];
	//Beware of overflow in weight
	vector<int> dist(n + 1, 1e9);

	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}

	set <pair<int, int>> st;
	//Heres source node is 1
	st.insert({0, 1}); //distance , node
	dist[1] = 0;

	while (!st.empty())
	{
		auto itr = st.begin();
		pair<int, int> p = *st.begin();
		// take out minimum distance node and try to pull all its adjacent node closer
		st.erase(itr);

		for (auto neigh : adj[p.se])
		{
			if (dist[neigh.fi] > dist[p.se] + neigh.se)
			{
				auto it = st.find({dist[neigh.fi], neigh.fi});
				//if that node is already in the set
				//we need to erase it because we find a better distance
				if (it != st.end())
					st.erase(it);

				//update the distance and push it in the set
				dist[neigh.fi] = dist[p.se] + neigh.se;
				st.insert({dist[neigh.fi], neigh.fi});
			}

		}
	}

	// print shortest distance to all other nodes except source node
	// Here sourece node is 1
	for (int i = 2 ; i <= n; i++)
		cout << dist[i] << " ";

	cout << endl;
}
int main()
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