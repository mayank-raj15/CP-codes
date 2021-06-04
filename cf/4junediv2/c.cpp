
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;

#define mod 1000000007
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define pii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define inf 1e18
#define sp(ans, pre) fixed << setprecision(pre) << y
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define all(x) x.begin(),x.end()
#define pb push_back
#define srt(v) sort(v.begin(), v.end())


void solve()
{
	string s;
	cin >> s;
	ll ans = 0;
	int n = s.length();
	vector<char> b(2, '?');
	ll cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			if (s[i] == '1')
			{
				b[0] = '1';
				b[1] = '0';
			}
			else if (s[i] == '0')
			{
				b[0] = '0';
				b[1] = '1';
			}
			cnt++;
			continue;
		}

		if (s[i] == '?')
		{
			cnt++;
			continue;
		}

		if (b[i % 2] == s[i] || b[i % 2] == '?')
		{
			if (s[i] != '?' && b[i % 2] == '?')
			{
				b[i % 2] = s[i];
				if (s[i] == '0')
					b[(i + 1) % 2] = '1';
				else
					b[(i + 1) % 2] = '0';
			}
			cnt++;
			continue;
		}
		else
		{
			i--;
			int j = 0;
			while (i >= 0 && s[i] == '?')
			{
				i--;
				cnt--;
				j++;
			}

			ans += (cnt * (cnt + 1)) / 2 + cnt * j;
			cnt = 0;

			b[0] = '?';
			b[1] = '?';
		}
	}

	ans += (cnt * (cnt + 1)) / 2;
	cout << ans << "\n";
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