#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int bfs(int n) {
	queue<pair<int, int>> q;  
	vector<bool> visited(n + 1, false);

	q.push({ n, 0 });
	visited[n] = true;

	while (!q.empty()) {
		int current = q.front().first;
		int steps = q.front().second;
		q.pop();

		if (current == 1) {
			return steps;
		}

		if (current % 3 == 0 && !visited[current / 3]) {
			q.push({ current / 3, steps + 1 });
			visited[current / 3] = true;
		}

		if (current % 2 == 0 && !visited[current / 2]) {
			q.push({ current / 2, steps + 1 });
			visited[current / 2] = true;
		}

		if (!visited[current - 1]) {
			q.push({ current - 1, steps + 1 });
			visited[current - 1] = true;
		}
	}

	return -1;  // 불가능한 경우는 없음
}

int main() {
	int n;
	cin >> n;

	cout << bfs(n) << endl;

	return 0;
}
