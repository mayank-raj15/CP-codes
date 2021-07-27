#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int sum;
	cin >> sum;
	sort(a, a + n);
	vector<vector<int>> ans;
	for (int i = 0; i < n - 2; i++)
	{
		if (a[i] >= sum)
			break;

		int cur;
		int low = i + 1, high = n - 1;
		while (low < high)
		{
			cur = a[i] + a[low] + a[high];
			if (cur > sum)
				high--;
			else
			{
				for (int x = low + 1; x <= high; x++)
				{
					cout << "(" << a[i] << ", " << a[low] << ", " << a[x] << ")\n";
				}
				low++;
			}
		}
	}

}