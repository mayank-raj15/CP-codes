
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
	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	// int temp;
	set<int> set;
	unordered_map<int, int> map;
	for (int i = 0; i < n; i++)
	{
		set.insert(a[i]);
	}

	srt(a);

	map[a[0]] = 1;

	for (int i = 1; i < n; i++)
	{
		map[a[i]] = 1 + map[a[i - 1]];
	}

	while (q--)
	{
		int x;
		cin >> x;
		if (set.find(x) != set.end())
			cout << 0 << "\n";
		else
		{
			if (x > a[n - 1])
			{
				cout << "POSITIVE\n";
				continue;
			}

			auto it = set.lower_bound(x);
			int neg = n - map[*it] + 1;
			if (neg % 2)
				cout << "NEGATIVE\n";
			else
				cout << "POSITIVE\n";
		}
	}
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

	// int t;
	// cin >> t;
	// while (t--)
	// {
	solve();
	// }

#ifndef ONLINE_JUDGE
	auto end = chrono::steady_clock::now();

	auto diff = end - start;

	cout << "\nTime taken: ";
	cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
#endif
}