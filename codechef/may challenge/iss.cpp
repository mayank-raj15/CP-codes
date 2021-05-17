
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

bool prime[4000002];

void SieveOfEratosthenes(int n)
{
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= n; p++)
	{
		if (prime[p] == true)
		{
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
}

void solve()
{
	int k;
	cin >> k;
	int cur =  5 + (k - 1) * 4;
	ll sum = 0;
	ll j = 3;

	if (prime[cur])
	{
		sum = cur + 2 * k - 1;
		cout << sum << "\n";
		return;
	}

	for (int i = 2; i * i <= cur; i++)
	{
		if (cur % i == 0)
		{

		}
	}

}

int main()
{
	send help
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	SieveOfEratosthenes(4000002);
	int t;
	cin >> t;
	while (t--)
		solve();
}