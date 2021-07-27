#include <bits/stdc++.h>
using namespace std;

int getMissingElement(vector<int> &a, int n)
{
	int d = (a[n - 1] - a[0]) / n;
	int low = 0, high = n - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (mid != 0 && a[mid - 1] + d < a[mid])
			return a[mid - 1] + d;
		else if (mid != n - 1 && a[mid] + d < a[mid + 1])
			return a[mid] + d;
		else if (a[mid] > a[0] + d * mid)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];


	cout << getMissingElement(a, n);
}