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

int crossPaths;

int simplePaths(vector<vector<int>> &adjList, int src, int parent)
{
    int paths = 0;
    for (int i : adjList[src])
    {
        if (i != parent)
        {
            int sp = simplePaths(adjList, i, src);
            crossPaths += (paths % mod * sp % mod) % mod;
            paths = (paths + sp * 2) % mod;
        }
    }

    return (paths + 1) % mod;
}

int32_t main()
{
    init();
    int t;
    cin >> t;
    rep(tt, 0, t)
    {
        int n;
        cin >> n;
        vector<vi> adjList(n);
        crossPaths = 0;
        rep(i, 0, n - 1)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }

        int paths = simplePaths(adjList, 0, -1);
        cout << (paths + crossPaths) % mod << "\n";
    }
}