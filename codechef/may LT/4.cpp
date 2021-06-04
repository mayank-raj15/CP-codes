
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;

#define int long long
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

vector<int> maxSubArraySum(int a[], int size)
{
	int max_so_far = INT_MIN, max_ending_here = 0,
	    start = 0, end = 0, s = 0;

	for (int i = 0; i < size; i++ )
	{
		max_ending_here += a[i];

		if (max_so_far < max_ending_here)
		{
			max_so_far = max_ending_here;
			start = s;
			end = i;
		}

		if (max_ending_here < 0)
		{
			max_ending_here = 0;
			s = i + 1;
		}
	}
	return {max_so_far, start, end};
}

void kmax(int arr[], int k, int n, map<int, vector<int>> &ans) {

	for (int c = 0; c < k; c++) {

		int max_so_far = numeric_limits<int>::min();
		int max_here = 0;

		int start = 0, end = 0, s = 0;
		for (int i = 0; i < n; i++)
		{
			max_here += arr[i];
			if (max_so_far < max_here)
			{
				max_so_far = max_here;
				start = s;
				end = i;
			}
			if (max_here < 0)
			{
				max_here = 0;
				s = i + 1;
			}
		}

		for (int l = start; l <= end; l++)
		{
			ans[start].pb(arr[l]);
			arr[l] = numeric_limits<int>::min();
		}
		ans[start].pb(max_so_far);
	}
}

void solve()
{
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	map<int, vector<int>> ans;
	kmax(a, k, n, ans);
	int sum = 0, times = 1, start = 0;
	if (k == 1)
		cout << ans[0][ans[0].size() - 1] << "\n";
	else if (k == 2)
	{
		auto it = ans.begin();
		if ((it->second).size() <= 2)
		{
			++it;
			start = (it->second)[0];
			(it->second)[(it->second).size() - 1] = start;
			sum -= 2 * start;
		}

		for (auto it : ans)
		{
			sum += times * (it.se)[it.se.size() - 1];
			times++;
		}

		cout << sum << "\n";
	}
}

int32_t main()
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

	return 0;
}