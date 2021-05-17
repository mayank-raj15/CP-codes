#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
	ll n;
	cin >> n;
	ll a[n + 1] = {0};
	ll temp;
	for (int i = 1; i < n; i++)
	{
		cin >> temp;
		a[temp]++;
	}

	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 0)
		{
			cout << i;
			break;
		}
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