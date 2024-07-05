#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
vector<vector<int>> map;
vector<vector<vector<int>>> dist;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };



int bfs() {
	queue<tuple<int, int, int>> q;
	q.emplace(0, 0, 0);
	dist[0][0][0] = 1;

	while (!q.empty()) {
		int x, y, broken;
		tie(x, y, broken) = q.front();
		q.pop();

		if (x == n - 1 && y == m - 1) {
			return dist[x][y][broken];
		}

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (map[nx][ny] == 0 && dist[nx][ny][broken] == -1) {
					dist[nx][ny][broken] = dist[x][y][broken] + 1;
					q.emplace(nx, ny, broken);
				}
				if (map[nx][ny] == 1 && broken == 0 && dist[nx][ny][1] == -1) {
					dist[nx][ny][1] = dist[x][y][broken] + 1;
					q.emplace(nx, ny, 1);
				}
			}
		}
	}

	return -1;
}

int main() {

	cin >> n >> m;
	map.resize(n, vector<int>(m));
	dist.resize(n, vector<vector<int>>(m, vector<int>(2, -1)));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			map[i][j] = c - '0';
		}
	}

	int result = bfs();

	cout << result << '\n';

	return 0;
}
