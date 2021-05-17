
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

auto bSearch(vector<int> h, int n, int k)
{
	auto it1 = h.begin(), it2 = h.end();
	it2--;
	while (it1 <= it2)
	{
		auto mid = it1 + (it2 - it1) / 2;
		if (*mid == k)
		{
			return mid;
		}
		else if (*mid < k)
		{
			if (it1 == it2)
			{
				return mid;
			}
			else
			{
				mid++;
				it1 = mid;
			}
		}
		else if (*mid > k)
		{
			if (it1 == it2)
			{
				if (mid == h.begin())
				{
					return h.end();
				}
				else
				{
					mid--;
					return mid;
				}
			}
			else
			{
				mid--;
				it2 = mid;
			}
		}
	}
	return h.end();
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> h(n);
	int t[m];
	for (int i = 0; i < n; i++)
		cin >> h[i];
	for (int i = 0; i < m; i++)
		cin >> t[i];

	sort(all(h));

	cout << *bSearch(h, h.size(), 6);
	for (int i = 0; i < m; i++)
	{
		auto itr = bSearch(h, h.size(), t[i]);
		if (itr == h.end())
		{
			cout << "-1\n";
			continue;
		}

		cout << *itr << "\n";
		h.erase(itr);
	}
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