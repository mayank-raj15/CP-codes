#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, int i, int j, int &m, int &n)
{
	if (i >= m || i < 0 || j >= n || j < 0 || graph[i][j] == -1)
		return;

	int cur = graph[i][j];
	graph[i][j] = -1;
	if (cur == 0)
	{
		return;
	}

	vector<int> dir = {0, 1, 1, 0, -1, 1, -1, -1, 0};
	for (int k = 0; k < 8; k++)
	{
		dfs(graph, i + dir[k], j + dir[k + 1], m, n);

	}
}

int main()
{
	int m, n;
	cin >> m >> n;
	vector<vector<int>> graph(m, vector<int> (n));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> graph[i][j];

	int ans = 0;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == 1)
			{
				dfs(graph, i, j, m, n);
				ans++;
			}
		}

	cout << ans - 1;
}


/*

Number of Islands
Given a matrix that consists of 1's and 0's where 1 represents land and 0 represents water. Connected lands surrounded by water is an island. Land can be connected in all 8 directions. Find the minimum of the bridges required to connect all the Islands.
Input Format

The first line contains the size of 2D matrix

The next line contains the elements of 2D matrix

Output Format

The output consists of the number of islands

Refer the sample output for formatting

Sample Input:

5 5

1 1 0 0 0

0 1 0 0 1

1 0 0 1 1

0 0 0 0 0

1 0 1 0 1

Sample Output:

4

*