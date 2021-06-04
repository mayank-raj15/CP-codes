
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
#define inf 1e18
#define sp(ans, pre) fixed << setprecision(pre) << y
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define all(x) x.begin(),x.end()
#define pb push_back
#define srt(v) sort(v.begin(), v.end())

set<int> pn;

void Sieve(int n)
{
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= n; p++)
	{
		if (prime[p] == true)
		{
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}

	for (int p = 2; p <= n; p++)
		if (prime[p])
			pn.insert(p);

}

void solve()
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int distance = 0;
	for (int i = 1; i < n; i++)
	{
		if (s[i] == s[i - 1])
			distance += 2;
		else
			distance += 1;
	}

	while (k--)
	{
		int dist = distance;
		int i;
		cin >> i;
		i = i - 1;
		if (s[i] == '0')
			s[i] = '1';
		else
			s[i] = '0';

		if (i == 0)
		{
			if (n > 1 && s[i + 1] == s[i])
				dist += 1;
			else if (n > 1 && s[i + 1] != s[i])
				dist -= 1;
		}
		else if (i == n - 1)
		{
			if (n > 1 && s[i - 1] == s[i])
				dist += 1;
			else if (n > 1 && s[i - 1] != s[i])
				dist -= 1;
		}
		else
		{

			if (s[i] == s[i - 1])
				dist += 1;
			else
				dist -= 1;

			if (s[i] == s[i + 1])
				dist += 1;
			else
				dist -= 1;
		}

		cout << dist << "\n";

		distance = dist;
	}
}

int main()
{
	//for time calculation
#ifndef ONLINE_JUDGE
	auto start = chrono::steady_clock::now();
#endif

	send help
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	Sieve();
	while (t--)
	{
		solve();
	}

#ifndef ONLINE_JUDGE
	auto end = chrono::steady_clock::now();

	auto diff = end - start;

	cout << "\nTime taken: ";
	cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
#endif
}