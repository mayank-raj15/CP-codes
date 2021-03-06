#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int m = s1.length(), n = s2.length();

	vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{

			if (i == 0)
				dp[i][j] = j;

			else if (j == 0)
				dp[i][j] = i;

			else if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];

			else
				dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
		}
	}

	cout << dp[m][n];
}