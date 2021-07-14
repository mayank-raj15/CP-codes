#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int apples;
	cin >> apples;
	long long int sideLength = 0, sum = 0, ans;
	while (sum < apples)
	{
		sideLength++;
		sum += 12 * sideLength * sideLength;
	}

	ans = 8 * sideLength;

	cout << ans;

}

/*

For s=1;
Perimeter = 8*s
total apples per level  = 12*s*s
total apples in square of side 2s = 2s*(s+1)*(2s+1)

2 1 2
1 0 1
2 1 2


Allies apple trees
In a garden, there are several apple trees planted in a grid format. Each point (i, j) in the grid has |i| + |j| apples. Allie can buy a square plot centered at (0, 0). Find the minimum perimeter of the plot (1 unit having length = 1) such that she can collect at least X apples. All plants on the perimeter of the plot are also included.
Input Format

X denotes the number of apples Allie has to collect.

Output Format

Your function should return the minimum perimeter of plot that should be bought by Allie.

Explanation

Apples in each unit square will be |i| + |j| as length of 1 unit will contain 0 apples (0,0). Hence, plot of side length 2 will be taken, keeping(0,0) in the center.

Refer the sample output for formatting

Sample Input:

1

Sample Output:

8

*/