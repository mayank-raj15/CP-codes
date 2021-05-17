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

void solve()
{
	ll n;
	cin >> n;
	ll sum = 0;
	sum = n * (n + 1) / 2;
	if (sum % 2)
	{
		cout << "NO";
		return;
	}

	cout << "YES\n";
	sum /= 2;
	ll cur = 0;
	vector<int> a(n + 1, 0);
	int cnt1 = 0;
	for (ll i = n; i >= 1; i--)
	{
		if (cur + i <= sum)
		{
			cur += i;
			a[i]++;
			cnt1++;
		}
		if (cur == sum)
			break;
	}

	cout << cnt1 << "\n";

	for (int i = 1; i <= n; i++)
		if (a[i])
			cout << i << " ";

	cout << "\n";
	cout << n - cnt1 << "\n";

	for (int i = 1; i <= n; i++)
		if (a[i] == 0)
			cout << i << " ";


}

int main()
{
	send help
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// int t;
	// cin >> t;
	// while (t--)
	solve();
}