
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
	char a[3][3];
	int nx = 0, no = 0, nu = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'X')
				nx++;
			else if (a[i][j] == 'O')
				no++;
			else
				nu++;
		}
	}

	if (no > nx || nx > no + 1)
	{
		cout << "3\n";
		return;
	}

	bool xwin = false, owin = false;
	int xc = 0, oc = 0;

	for (int i = 0; i < 3; i++)
	{
		xc = 0, oc = 0;
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] == 'X')
				xc++;
			else if (a[i][j] == 'O')
				oc++;
		}
		if (xc == 3)
			xwin = true;
		else if (oc == 3)
			owin = true;
	}

	for (int j = 0; j < 3; j++)
	{
		xc = 0, oc = 0;
		for (int i = 0; i < 3; i++)
		{
			if (a[i][j] == 'X')
				xc++;
			else if (a[i][j] == 'O')
				oc++;
		}
		if (xc == 3)
			xwin = true;
		else if (oc == 3)
			owin = true;
	}

	xc = 0, oc = 0;
	for (int i = 0, j = 0; i < 3; i++, j++)
	{
		if (a[i][j] == 'X')
			xc++;
		else if (a[i][j] == 'O')
			oc++;
	}

	if (xc == 3)
		xwin = true;
	else if (oc == 3)
		owin = true;

	xc = 0, oc = 0;
	for (int i = 0, j = 2; i < 3; i++, j--)
	{
		if (a[i][j] == 'X')
			xc++;
		else if (a[i][j] == 'O')
			oc++;
	}

	if (xc == 3)
		xwin = true;
	else if (oc == 3)
		owin = true;

	if (xwin && owin)
		cout << "3\n";
	else if (owin && nx > no)
		cout << "3\n";
	else if (xwin && nx == no)
		cout << "3\n";
	else if (nu == 0 || xwin || owin)
		cout << "1\n";
	else
		cout << "2\n";

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