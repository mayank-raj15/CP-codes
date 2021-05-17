#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
	ll n;
	cin >> n;
	for (ll i = 1; i <= n; i++)
	{
		ll ans = i * i * (i * i - 1) / 2 - 4 * (i - 1) * (i - 2);
		cout << ans << "\n";
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// int t;
	// cin >> t;
	// while (t--)
	solve();
}