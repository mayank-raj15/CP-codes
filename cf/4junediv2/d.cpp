
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


void getCount(vector<pii> &teams, int n, int k, int ind, char res)
{
	int rnd = k - 1, cr = 1, pr = 1;
	while (ind > 0)
	{
		ind -= pow(2, rnd);
		pr = cr;
		cr += pow(2, rnd);
		rnd--;
	}
	int mv = 0;
	for (int i = ind; i <= n;)
	{
		if (rnd == k - 1)
		{
			if (res == '0')
				teams[i] = {1, 0};
			else if (res == '1')
				teams[i] = {1, 1};
			else
				teams[i] = {2, 2};
		}
		else
		{
			mv = i - cr;
			int prev = pr + 2 * mv;
			if (res == '0')
				teams[i] = {teams[prev].fi, 0};
			else if (res == '1')
				teams[i] = {teams[prev + 1].fi, 1};
			else
				teams[i] = {teams[prev].fi + teams[prev + 1].fi, 2};
		}
		rnd--;
		cr += pow(2, rnd);
		i = cr + pow(2, rnd - 1) + mv / 2;
	}
}

void solve()
{
	string s;
	cin >> s;
	int n = s.length();
	int k = log2(n + 1);
	vector<pii> teams(n + 1);
	int cr = 1, pr = 1, rnd = 1;

	for (int i = 1; i <= n; i++)
	{
		teams[i] = {1, 2};
	}

	for (int i = 1; i < n; i++)
	{
		if (rnd == k - 1)
		{
			if (s[i - 1] == '0')
				teams[i] = {1, 0};
			else if (s[i - 1] == '1')
				teams[i] = {1, 1};
			else
				teams[i] = {2, 2};
		}
		else
		{
			int mv = i - cr;
			int prev = pr + 2 * mv;
			if (s[i - 1] == '0')
				teams[i] = {teams[prev].fi, 0};
			else if (s[i - 1] == '1')
				teams[i] = {teams[prev + 1].fi, 1};
			else
				teams[i] = {teams[prev].fi + teams[prev + 1].fi, 2};
		}
		pr = cr;
		cr += pow(2, rnd);
		rnd--;
	}

	int q;
	cin >> q;
	while (q--)
	{
		int ind;
		char res;
		cin >> ind >> res;

		getCount(teams, n, k, ind, res);

		cout << teams[n].fi << "\n";
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