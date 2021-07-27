#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int mx = INT_MIN, mn = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}

	int mxi, mni;

	for (int i = 0; i < n; i++)
	{
		if (mx == a[i])
			mxi = i;
		if (mn == a[i])
			mni = i;
	}

	int ans = n - 1 - mni + mxi;
	if (mxi > mni)
		ans--;
	cout << ans;
}