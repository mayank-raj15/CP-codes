
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
	int n;
	cin >> n;
	unordered_map<int, int> a;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		a[temp - i]++;
	}

	ll ans = 0;
	for (auto it : a)
	{
		ans += (it.second * (it.second - 1)) / 2;
	}

	cout << ans << "\n";
}

int main()
{
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
}