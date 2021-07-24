#include <bits/stdc++.h>
using namespace std;

void getPaths(vector<vector<int>> &maze, int i, int j, int &n, int &ans)
{
	if (i == n - 1 && j == n - 1)
	{
		ans++;
		return;
	}

	if (i < 0 || i >= n || j < 0 || j >= n || maze[i][j] == -1 || maze[i][j] == 1)
		return;

	maze[i][j] = -1;

	vector<int> dir = {0, 1, 0, -1, 0};
	for (int k = 0; k < 4; k++)
	{
		getPaths(maze, i + dir[k], j + dir[k + 1], n, ans);
	}

	maze[i][j] = 0;

}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> maze(n, vector<int> (n));

	// 0 for open, 1 for close
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> maze[i][j];

	int ans = 0;
	getPaths(maze, 0, 0, n, ans);
	cout << ans;
}