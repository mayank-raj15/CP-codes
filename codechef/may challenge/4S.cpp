#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define maxHeap priority_queue<int>;
#define minHeap priority_queue<int, vi, greater<int>>
#define mod 1000000007
#define inf 1e18
#define sp(ans, pre) fixed << setprecision(pre) << y
#define rep(i, s, n) for (int i = s; i < n; i++)
#define pb push_back
#define srt(v) sort(v.begin(), v.end())
#define all(v) begin(v), end(v)

int ans;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int depthCalc(vector<vector<int>> &adjList, int src, vi &depths, vector<bool> &visited)
{
    visited[src] = true;

    int d = 1;
    for (int i : adjList[src])
    {
        if (!visited[i])
            d = max(d, 1 + depthCalc(adjList, i, depths, visited));
        else
            d = max(d, 1 + depths[i]);
    }

    depths[src] = d;
    return d;
}

int childrens(vector<vector<int>> &adjList, int src, vi &childs, vector<bool> &visited)
{
    if (visited[src])
        return 0;

    visited[src] = true;

    int bacche = 0;
    for (int i : adjList[src])
        bacche += childrens(adjList, i, childs, visited);

    childs[src] = bacche + 1;
    return bacche + 1;
}

bool comp(pii i, pii j)
{
    return i >= j;
}

// struct comp
// {
//     bool operator()(pair<int, pii> p1, pair<int, pii> p2)
//     {
//         // return "true" if "p1" is ordered
//         // before "p2", for example:

//         return p1.first >= p2.first;
//     }
// };

void addValues(vector<vector<pii>> &graph, vector<bool> &visited, int n, int ver, int val)
{
    visited[ver] = true;
    ans = (ans + val) % mod;
    int j = 1;

    for (auto v : graph[ver])
    {
        if (!visited[v.second])
        {
            int cur = val * j;
            addValues(graph, visited, n, v.second, cur % mod);
            j++;
        }
    }
}

int32_t main()
{
    init();
    int t;
    cin >> t;
    rep(tt, 0, t)
    {
        ans = 0;
        int n, x;
        cin >> n >> x;
        vector<vector<int>> adjList(n + 1);
        vi childs(n + 1, 0), depths(n + 1, 0), val(n + 1, 0);
        vector<bool> visited(n + 1, false);

        int u, v;
        rep(i, 0, n - 1)
        {
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        childrens(adjList, 1, childs, visited);
        visited = vector<bool>(n + 1, false);
        depthCalc(adjList, 1, depths, visited);

        visited = vector<bool>(n + 1, false);

        vector<vector<pii>> graph(n + 1);

        for (int i = 1; i <= n; i++)
        {
            for (int u : adjList[i])
            {
                graph[i].push_back(make_pair(childs[u] - depths[u], u));
            }

            sort(all(graph[i]), comp);
        }

        addValues(graph, visited, n, 1, x);

        cout << ans << "\n";
    }

    return 0;
}