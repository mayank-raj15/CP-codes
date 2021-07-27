#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int k = 1, y = n * (n + 1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j < i)
			{
				cout << "  ";
				continue;
			}
			cout << k << "*";
			k++;
		}

		int z = y - k + 1 ;

		for (int j = i; j < n; j++)
		{
			++z;
			if (j == n - 1)
				cout << z ;
			else
				cout << z << "*";
		}

		cout << "\n";
	}
}