
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

int po2(ll x, int n)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return x;

	ll temp = po2((x * x) % mod, n / 2);

	if (n % 2 == 0)
		return temp % mod;
	else
		return (x * temp) % mod;
}

void solve()
{
	int n;
	cin >> n;

	ll x = 2;
	cout << po2(x, n - 1) << "\n";
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
		solve();
}