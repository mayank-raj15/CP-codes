
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
	int n, m, a, b, s;
	cin >> n >> m;
	map<int, int> map;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		for (int j = a; j <= b; j++)
			map[j]++;
	}

	while (m--)
	{
		cin >> s;
		auto it = map.lower_bound(s);
		int mn = 0;
		if (it == map.begin())
		{
			int f = 0;
		}
		else if (it == map.end())
		{
			--it;
		}
		else
		{
			auto it2 = it;
			it2--;
			if (abs((*it).first - s) >= abs((*it2).first - s))
				it = it2;
		}
		cout << (*it).first << " ";
		(*it).second--;
		if ((*it).second == 0)
			map.erase((*it).first);
	}
	cout << "\n";
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