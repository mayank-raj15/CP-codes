#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &a, int l, int r)
{
	int n = a.size();
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (mid != 0 && mid != n - 1 && a[mid - 1] != a[mid] && a[mid] != a[mid + 1])
			return a[mid];
		else if (mid == n - 1 && a[mid] != a[mid - 1])
			return a[mid];
		else if (mid == 0 && a[mid] != a[mid + 1])
			return a[mid];
		else if (mid != 0 && mid % 2 && a[mid] == a[mid - 1])
			l = mid + 1;
		else
			r = mid - 1;

	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << binarySearch(a, 0, n - 1);
}