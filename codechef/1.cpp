
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

void bfsPrint(vector<vector<int>> graph, queue<int> &q, vector<bool> &visited, int da[], int dist)
{
	if (q.empty())
		return;
	int v = q.front();
	q.pop();
	dist++;
	for (auto i : graph[v])
	{
		if (!visited[i])
		{
			q.push(i);
			visited[i] = true;
			da[i] = dist;
		}
	}
	bfsPrint(graph, q, visited, da, dist);
}

void bfs(int vertex, vector<vector<int>> graph, int da[])
{
	vector<bool> visited(graph.size(), 0);
	queue<int> q;
	q.push(vertex);
	bfsPrint(graph, q, visited, da, 0);
}

void solve()
{
	int n, k, a;
	cin >> n;
	int sp[k];

	vector<vector<int>> graph(n + 1);

	for (int i = 0; i < k; i++)
		cin >> sp[k];
	int x, y;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	int da[n + 1];
	bfs(a, graph, da);

	for (int i = 0; i < k; i++)
		cout << da[i] << " ";

	cout << "\n";
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
		solve();
}