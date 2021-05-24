
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
#define inf 1e18
#define sp(ans, pre) fixed << setprecision(pre) << y
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define all(x) x.begin(),x.end()
#define pb push_back
#define srt(v) sort(v.begin(), v.end())

vector<ll> v;

void solve()
{
	vector<ll> a = v;
	ll x, y;
	cin >> x >> y;
	ll min = 0;
	if (y % x != 0)
	{
		cout << "-1\n";
		return;
	}
	y = y / x;
	int k = 59;
	while (y > 0 && k > 0)
	{
		if (a[k] <= y)
		{
			y -= a[k];
			min += k;
			if (y == 0)
			{
				cout << min << "\n";
				return;
			}
			min += 1;
		}
		k--;
	}
	cout << "-1\n";
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

	v.push_back(0);
	v.push_back(1);
	for (int i = 2; i < 60; i++)
	{
		ll k = (v[i - 1] + 1) * 2 - 1;
		v.push_back(k);
	}

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