
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
	int n, k;
	cin >> n >> k;
	int a[n];
	unordered_map<int, int> map;
	unordered_map<int, bool> cond;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		map[a[i]]++;
		cond[a[i]] = false;
	}

	int cnt = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < n; i++)
	{
		if (pq.size() == k && cond[a[i]] == false)
		{
			pair<int, int> p = pq.top();
			pq.pop();
			cond[p.second] = false;
		}

		map[a[i]]--;
		if (cond[a[i]] == false)
		{
			cond[a[i]] = true;
			pq.push(make_pair(map[a[i]], a[i]));
			cnt++;
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
	{
		solve();
	}
}