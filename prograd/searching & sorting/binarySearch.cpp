#include <bits/stdc++.h>
using namespace std;

int bs(int a[], int n, int k)
{
	int low = 0, high = n - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (a[mid] == k)
			return mid;
		else if (a[mid] > k)
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
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int k;
	cin >> k;
	int ans = bs(a, n, k);
	if (ans == -1)
		cout << "Not found";
	else
		cout << ans;
}