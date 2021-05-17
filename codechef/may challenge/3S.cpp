#include <bits/stdc++.h>

using namespace std;

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

// int findNodes(vector<vi> &adjList, int src, vector<bool> &visited, vector<int> &nodes)
// {
//     if (visited[src])
//         return 0;
//     visited[src] = true;
//     int branches = adjList[src].size();
//     for (int i : adjList[src])
//     {
//         branches = max(branches, findNodes(adjList, i, visited, nodes));
//     }

//     nodes[src] = branches;
//     return nodes[src];
// }

void solve()
{
    int n, m;
    long long counter = 0;
    cin >> n >> m;

    vector<int> v[m + 1];

    for (int i = min(m, n); i >= 2; i--)
    {
        int current = m - m % i;
        if (v[current].size() > 0)
        {
            for (int cur : v[current])
            {
                if (cur < i)
                    counter++;
                else
                    break;
            }
            continue;
        }

        for (int j = 1; j * j <= current && j < i; j++)
        {
            if (current % j == 0)
            {
                counter++;
                v[current].push_back(j);
                if (current / j < i && j != current / j)
                {
                    counter++;
                    v[current].push_back(current / j);
                }
            }
        }
        sort(all(v[current]));
    }

    for (int i = m + 1; i <= n; i++)
        counter += i - 1;

    cout << counter << "\n";
}

int32_t main()
{
    init();

    int t;
    cin >> t;
    rep(tt, 0, t)
    {
        solve();
    }
}