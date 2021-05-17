#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
	ll x, y, ans;
	cin >> x >> y;
	if (x > y)
	{
		if (x % 2)
		{
			ans = (x - 1) * (x - 1) + 1;
			ans += y - 1;
		}
		else
		{
			ans = x * x;
			ans -= y - 1;
		}
	}
	else
	{
		if (y % 2)
		{
			ans = y * y;
			ans -= x - 1;
		}
		else
		{
			ans = (y - 1) * (y - 1) + 1;
			ans += x - 1;
		}
	}
	cout << ans << "\n";

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) solve();
}