#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
	string s;
	cin >> s;
	int cnt = 1, ans = 1;
	int n = s.length();
	for (int i = 1; i < n; i++)
	{
		if (s[i] == s[i - 1])
			cnt++;
		else
			cnt = 1;
		ans = max(ans, cnt);
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