
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

ll ans = INT_MAX;

void check(ll s1, ll s2, vector<ll> &wt, int ind)
{
	if (ind == wt.size())
	{
		ans = min(ans, abs(s2 - s1));
		return ;
	}

	ll s11 = s1, s22 = s2;
	s11 += wt[ind];
	s22 += wt[ind];
	check(s11, s2, wt, ind + 1);
	check(s1, s22, wt, ind + 1);
}

void solve()
{
	int n;
	cin >> n;
	vector<ll> weights(n);
	for (int i = 0; i < n; i++)
		cin >> weights[i];
	ll s1 = 0, s2 = 0;
	check(s1, s2, weights, 0);
	cout << ans;
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