#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> money(n);
	for (int i = 0; i < n; i++)
		cin >> money[i];

	vector<int> dp(n + 1, 0);
	dp[0] = 0, dp[1] = money[0];
	for (int i = 2; i <= n; i++)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + money[i - 1]);
	}

	cout << dp[n];
}





























/*

House Robber Problem
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night. Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
Input Format

The first line consists of size of an array

The second line consists of array of elements separated by space

Output Format

The output consists of maximum amount stolen

Constraints

1 <= n <= 1000

1 <= Ai <= 10000

Refer the sample output for formatting

Sample Input

4

11 12 13 11

Sample Output

24

Explanation

Rob house 1 (money = 11) and then rob house 3 (money = 13).

Total amount you can rob = 11 + 13 = 24.

*/