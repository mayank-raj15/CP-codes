#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> price(n);
	for (int i = 0; i < n; i++)
		cin >> price[i];

	int profit = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (price[i] < price[i + 1])
			profit += price[i + 1] - price[i];
	}

	cout << profit;
}