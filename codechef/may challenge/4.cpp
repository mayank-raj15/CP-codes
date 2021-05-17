
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

int size[100001], depth[100001];

bool comp(int i, int j)
{
	if (size[i] - depth[i] >= size[j] - depth[j])
		return true;
	else
		return false;
}

int calcDepth(vector<vector<int>> &graph, vector<bool> &visited, int n, int v)
{
	visited[v] = true;

	int td = 1;

	for (auto u : graph[v])
	{
		if (!visited[u])
		{
			td = max(td, 1 + calcDepth(graph, visited, n, u));
		}
	}

	depth[v] = td;
	return depth[v];
}

int calcSize(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &deg, int n, int v)
{
	visited[v] = true;
	int sz = 0;
	for (int u : graph[v])
	{
		if (!visited[u])
			sz += calcSize(graph, visited, deg, n, u);
	}

	size[v] = sz + 1;
	return size[v];
}

void addValues(vector<vector<int>> &graph, vector<bool> &visited, int n, int ver, ll val)
{
	visited[ver] = true;
	ans = (ans + val) % mod;
	int j = 1;

	for (auto v : graph[ver])
	{
		if (!visited[v])
		{
			ll cur = val * j;
			addValues(graph, visited, n, v, cur % mod);
			j++;
		}
	}
}

void solve()
{
	int n, x, u, v;
	cin >> n >> x;
	vector<vector<int>> graph(n + 1);
	vector<int> deg(n + 1, 0);

	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	vector<bool> visited(n + 1, false);
	calcDepth(graph, visited, n, 1);

	for (int i = 1; i <= n; i++)
		visited[i] = false;
	calcSize(graph, visited, deg, n, 1);

	for (int i = 1; i <= n; i++)
		visited[i] = false;

	for (int i = 1; i <= n; i++)
		cout << depth[i] << " ";

	// for (int i = 1; i <= n; i++)
	// {
	// 	sort(all(graph[i]), comp);
	// }


	// addValues(graph, visited, n, 1, x);

	// cout << ans << "\n";
}

int main()
{
	//for time calculation
// #ifndef ONLINE_JUDGE
// 	auto start = chrono::steady_clock::now();
// #endif

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

// #ifndef ONLINE_JUDGE
// 	auto end = chrono::steady_clock::now();

// 	auto diff = end - start;

// 	cout << "\nTime taken: ";
// 	cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
// #endif
}