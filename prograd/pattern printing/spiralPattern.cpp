#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	int rmin = 0, rmax = n - 1, cmin = 0, cmax = n - 1, k = 0, dir = 0;
	while (k < n * n)
	{
		switch (dir)
		{
		case 0:
			for (int j = cmin; j <= cmax; j++)
			{
				cout << a[rmin][j] << " ";
				k++;
			}
			rmin++;
			dir = 1;
			break;
		case 1:
			for (int i = rmin; i <= rmax; i++)
			{
				cout << a[i][cmax] << " ";
				k++;
			}
			cmax--;
			dir = 2;
			break;
		case 2:
			for (int j = cmax; j >= cmin; j--)
			{
				cout << a[rmax][j] << " ";
				k++;
			}
			rmax--;
			dir = 3;
			break;
		case 3:
			for (int i = rmax; i >= rmin; i--)
			{
				cout << a[i][cmin] << " ";
				k++;
			}
			cmin++;
			dir = 0;
			break;
		}
	}
}