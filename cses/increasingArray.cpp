#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
	int n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	ll ans = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1])
		{
			ans += a[i - 1] - a[i];
			a[i] = a[i - 1];
		}
	}

	cout << ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// int t;
	// cin >> t;
	// while (t--) solve();
	solve();
}