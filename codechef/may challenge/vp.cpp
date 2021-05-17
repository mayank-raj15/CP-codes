
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;

#define mod 1000000007
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define fi first
#define se second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define all(x) x.begin(),x.end()

ll ans;

ll getPaths(vector<vector<int>> &graph, int src, vector<bool> &visited)
{
	ll cur = 0;
	visited[src] = true;
	for (int i : graph[src])
	{
		if (!visited[i])
		{
			ll below = getPaths(graph, i, visited);
			ans += (cur % mod * below % mod) % mod;
			cur = (cur + below * 2) % mod;
		}
	}

	return (cur + 1) % mod;
}

void solve()
{
	int n, u, v;
	cin >> n;
	vector<vector<int>> graph(n + 1);

	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vector<bool> visited(n + 1, false);
	ll tempAns = getPaths(graph, 1, visited);

	cout << (ans + tempAns) % mod << "\n";
}

int main()
{
	send help
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--)
	{
		ans = 0;
		solve();
	}
}