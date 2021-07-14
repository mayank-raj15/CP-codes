#include <bits/stdc++.h>
using namespace std;

int getPosition(int n, int k)
{
	if (n == 1)
		return 0;

	return (getPosition(n - 1, k) + k) % n ;
}

int main()
{
	int n, k;
	cin >> n >> k;
	cout << getPosition(n, k) + 1;
}

/*

Josepheus Problem
There are n people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom. Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in a circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.
Input Format

The first line consists of an integer value which is total number of people.

The second line consists of kth person to be killed in a circle.

Output Format

We have to obtain the same stack on the third rod.

Constraints

1 <= N <= 100000

1 <= k <= 500

Refer the sample output for formatting

Sample Input:

100

2

Sample Output:

73

*/