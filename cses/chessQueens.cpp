
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

int cnt;

void countPerm(vector<vector<bool>> &available, int col, vector<bool> &up, vector<bool> &down, vector<bool> &rows)
{
	if (col == 8)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < 8; i++)
	{
		if (available[i][col] && !rows[i] && !up[8 - (i - col)] && !down[i + col])
		{
			rows[i] = true, up[8 - (i - col)] = true, down[i + col] = true;
			countPerm(available, col + 1, up, down, rows);
			rows[i] = false, up[8 - (i - col)] = false, down[i + col] = false;
		}
	}
}

void checkPossibilities(vector<vector<bool>> &available)
{
	vector<bool> up(15, false), down(15, false), rows(8, false);
	countPerm(available, 0, up, down, rows);
}

void solve()
{
	vector<vector<bool>> available(8, vector<bool> (8, true));
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			char temp;
			cin >> temp;
			if (temp == '*')
				available[i][j] = false;
		}
	}

	checkPossibilities(available);

	cout << cnt;
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

	// int t;
	// cin >> t;
	// while (t--)
	// {
	solve();
	// }

#ifndef ONLINE_JUDGE
	auto end = chrono::steady_clock::now();

	auto diff = end - start;

	cout << "\nTime taken: ";
	cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
#endif
}