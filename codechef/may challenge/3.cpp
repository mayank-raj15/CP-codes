
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

int binary_search_lower_bound(vector<int>& array, int target) {
	int lo = 0, hi = (int)array.size();
	int mid;

	while (lo < hi) {
		mid = lo + ((hi - lo) >> 1);
		int val = array[mid];
		if (target <= val)//array[mid])
			hi = mid;
		else
			lo = mid + 1;
	}

	return lo;
}

void solve()
{
	ll n, m, cnt = 0;
	cin >> n >> m;

	vector<int> v[m + 1];

	for (int i = min(m, n); i >= 2; i--)
	{
		int cur = m - m % i;
		if (v[cur].size() > 0)
		{
			int ind = binary_search_lower_bound(v[cur], i - 1);
			while (ind >= 0 && v[cur][ind] > i - 1)
				ind--;
			cnt += ind + 1;
			continue;
		}

		for (int j = 1; j * j <= cur && j < i; j++)
		{
			if (cur % j == 0)
			{
				cnt++;
				v[cur].push_back(j);
				if (cur / j < i && j != cur / j)
				{
					cnt++;
					v[cur].push_back(cur / j);
				}
			}
		}
		sort(all(v[cur]));
	}

	for (int i = m + 1; i <= n; i++)
	{
		cnt += i - 1;
	}

	cout << cnt << "\n";
}

int main()
{
	//for time calculation
// #ifndef ONLINE_JUDGE
// 	auto start = chrono::steady_clock::now();
// #endif

	send help
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--)
		solve();

// #ifndef ONLINE_JUDGE
// 	auto end = chrono::steady_clock::now();

// 	auto diff = end - start;

// 	cout << "\nTime taken: ";
// 	cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
// #endif
}