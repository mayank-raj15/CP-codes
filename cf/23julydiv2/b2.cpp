
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;

#define mod 1000000007
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define pii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define inf 1e18
#define sp(ans, pre) fixed << setprecision(pre) << y
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define all(x) x.begin(),x.end()
#define pb push_back
#define srt(v) sort(v.begin(), v.end())


void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	unordered_map<int, vector<int>> map;
	for (int i = 0; i < n; i++)
	{
		map[a[i]].push_back(i);
	}

	vector<vector<int>> color(k);
	int j = 0;
	for (auto it : map)
	{
		int cnt = 0;
		for (auto i : it.second)
		{
			color[j].push_back(i);
			cnt++;
			j++;
			if (j == k)
				j = 0;
			if (cnt == k)
				break;
		}
	}

	int mnsize = n;
	for (auto it : color)
		mnsize = min(mnsize, (int)it.size());

	for (int i = 0; i < n; i++)
		a[i] = 0;

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < mnsize; j++)
		{
			a[color[i][j]] = i + 1;
		}
	}



	for (auto i : a)
		cout << i << " ";
	cout << "\n";

}

int main()
{
	//for time calculation
#ifndef ONLINE_JUDGE
	auto start = chrono::steady_clock::now();
#endif

	send help
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}

#ifndef ONLINE_JUDGE
	auto end = chrono::steady_clock::now();

	auto diff = end - start;

	cout << "\nTime taken: ";
	cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
#endif
}