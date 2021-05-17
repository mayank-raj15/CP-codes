#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
	ll n;
	cin >> n;
	while (1)
	{
		cout << n << " ";
		if (n == 1)
			break;
		if (n % 2 == 0)
			n /= 2;
		else
			n = 3 * n + 1;
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
	// while (t--) solve();
	solve();
}