
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
#define X 3
#define Y 3

void setMap(unordered_map<int, int> &map, int a[X][Y], int i, int j)
{
	if ((j + i) % 2)
		return;
	map[j + i]++;
}

void solve()
{
	int a[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1)
				continue;
			cin >> a[i][j];
		}

	unordered_map<int, int> map;
	setMap(map, a, a[0][0], a[2][2]);
	setMap(map, a, a[0][2], a[2][0]);
	setMap(map, a, a[1][0], a[1][2]);
	setMap(map, a, a[0][1], a[2][1]);

	int mx = 0;
	for (auto it : map)
	{
		mx = max(it.second, mx);
	}

	int ans = mx;

	for (int i = 0; i < 3; i++)
		if (i != 1 && a[i][1] - a[i][0] == a[i][2] - a[i][1])
			ans ++;

	for (int j = 0; j < 3; j++)
		if (j != 1 && a[1][j] - a[0][j] == a[2][j] - a[1][j])
			ans++;

	cout << ans << "\n";

}

int main()
{
	//for time calculation
// #ifndef ONLINE_JUDGE
// 	auto start = chrono::steady_clock::now();
// #endif

	send help
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int i = 1, t;
	cin >> t;
	while (i <= t)
	{
		cout << "Case #" << i << ": ";
		solve();
		i++;
	}

// #ifndef ONLINE_JUDGE
// 	auto end = chrono::steady_clock::now();

// 	auto diff = end - start;

// 	cout << "\nTime taken: ";
// 	cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
// #endif
}