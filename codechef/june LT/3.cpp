
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
	ll a, b;
	cin >> a >> b;
	double num = (double)a / b;
	unordered_map<double, int> map;
	int cnt = 0;
	while (1)
	{
		num *= 2;
		cnt++;
		if (num > 1)
		{
			num -= 1;
			if (map[num] != 0)
				break;
			map[num]++;
		}
		if (num == 1)
		{
			cout << "Yes\n";
			return;
		}
		if (cnt > 32)
			break;
	}
	cout << "No\n";
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