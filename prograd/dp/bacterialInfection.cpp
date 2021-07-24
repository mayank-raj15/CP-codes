#include <bits/stdc++.h>
using namespace std;

struct Room
{
	int x, y, dist;
};

int getSteps(vector<vector<int>> &hospital, int i, int j, int &m, int &n)
{
	queue<Room> q;
	q.push({i, j, 1});
	int ans = 0;
	while (!q.empty())
	{
		Room cur = q.front();
		q.pop();
		int x = cur.x, y = cur.y, dist = cur.dist;
		ans = max(ans, dist);
		hospital[x][y] = -1;
		vector<int> dir = {0, 1, 0, -1, 0};
		for (int k = 0; k < 4; k++)
		{

			if (x + dir[k] >= m || x + dir[k] < 0 || y + dir[k + 1] >= n || y + dir[k + 1] < 0)
				continue;

			if (hospital[x + dir[k]][y + dir[k + 1]] != -1)
				q.push({x + dir[k], y + dir[k + 1], dist + 1});
		}
	}

	return ans;
}

int main()
{
	int m, n;
	cin >> m >> n;
	int x, y;
	cin >> x >> y;

	//1 represents infected
	vector<vector<int>> hospital(m, vector<int> (n, 0));
	hospital[x][y] = 1;

	cout << getSteps(hospital, x, y, m, n);

}