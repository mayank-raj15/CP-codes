
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

void solve()
{
	ll n;
	cin >> n;
	ll sz = 0;
	ll temp = n;
	while (temp > 0)
	{
		temp /= 10;
		sz++;
	}
	//cout << sz << "\n";
	ll cnt = 0, num = 0;
	//cout << sz << "\n";
	for (ll i = 0; i < sz; i++)
	{
		num += pow(10, i);
		for (ll j = 1; j <= 9; j++)
		{
			ll cur = num * j;
			if (cur <= n)
			{
				//cout << i << " " << j << " " << cur << "\n";
				cnt++;
			}
			else
				break;
		}
	}

	cout << cnt << "\n";
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