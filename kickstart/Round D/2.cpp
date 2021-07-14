
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
	unordered_map<int, int> map;
	int n, c, l, r;
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		cin >> l >> r;
		for (int j = l + 1; j < r; j++)
			map[j]++;
	}

	priority_queue<int> pq;
	for (auto it : map)
	{
		pq.push(it.second);
	}

	long long int ans = n;

	while (c-- && !pq.empty())
	{
		ans += pq.top();
		pq.pop();
	}

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