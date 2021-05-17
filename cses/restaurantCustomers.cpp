
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

void solve()
{
	int n, x, y;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back({x, y});
	}
	sort(all(v));

	int mn = -1, mx = -1, cnt = 0, ans = -1;

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			mn = v[i].fi;
			mx = v[i].se;
			cnt++;
			continue;
		}

		if (v[i].se < mx)
		{
			mx = v[i].se;
		}

		mn = v[i].fi;

		if (mn < mx)
			cnt++;
		else
		{
			ans = max(ans, cnt);
			cnt = 0;
			mx = INT_MAX;
		}
	}

	cout << ans;
}

int main()
{
	send help
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// int t;
	// cin >> t;
	// while (t--)
	solve();
}