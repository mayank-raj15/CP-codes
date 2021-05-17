#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int k;
	cin >> k;
	int f = 20;
	while (f--)
	{
		for (int i = 1; i <= 2 * k + 1; i++)
		{
			cout << k + i*i << " ";
		}
		cout << "\n";
		int sum = 0;
		for (int i = 1; i <= 2 * k ; i++)
		{
			int g = gcd(k + (i + 1) * (i + 1), k + i * i);
			sum += g;
			cout << g << " ";
		}
		cout << "\n" << k << ": " << sum;
		cout << "\n";
		k++;
	}
}