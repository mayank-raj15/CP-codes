
// Recursive Implementation - space consuming

#include <bits/stdc++.h>
using namespace std;

int getSum(int m, int n)
{
	if (m >= n)
		return 0;
	if (m % 15 != 0)
		return getSum(m + 1, n);

	return m + getSum(m + 15, n);
}

int main()
{
	int m, n;
	cin >> m >> n;
	int sum = getSum(m, n);
	cout << sum;
}

/*

Sum of numbers divisible by 3 and 5
You are required to implement this function: int SumNumbersDivisible(int m, int n); The function accepts 2 positive integers ‘m’ and ‘n’ as its arguments. You are required to calculate the sum of numbers divisible both by 3 and 5, between ‘m’ and ‘n’ inclusive the starting range and exclusive the ending range and return the same.

Input Format

The first line consists of an integer value m.

The second line consists of an integer value n.

Output Format

We have to obtained the output that is the sum of divisible of 3 and 5.

Constraints

0 < m <= n

Refer the sample output for formatting

Sample Input:

m: 12

n: 50

Sample Output:

90

Explanation:

The numbers divisible both by 3 and 5, between 12 and 50 both inclusive are{15, 30, 45} and their sum is 90.

*/