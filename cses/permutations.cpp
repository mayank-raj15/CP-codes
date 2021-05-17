#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
	int n;
	cin >> n;
	if (n != 1 && n < 4)
	{
		cout << -1;
		return ;
	}

	for (int i = 2; i <= n; i += 2)
		cout << i << " ";
	for (int i = 1; i <= n; i += 2)
		cout << i << " ";


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