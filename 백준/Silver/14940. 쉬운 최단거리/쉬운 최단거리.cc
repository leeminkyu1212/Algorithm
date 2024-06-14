#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    int n, m;
    cin >> n >> m;

    int** map = new int*[n];
    int** distance = new int*[n];
    for (int i = 0; i < n; ++i) {
        map[i] = new int[m];
        distance[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            distance[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    int target_x, target_y;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                target_x = i;
                target_y = j;
                distance[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == 1 && distance[nx][ny] == -1) {
                distance[nx][ny] = distance[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == 0) {
                cout << 0 << ' ';
            } else {
                cout << distance[i][j] << ' ';
            }
        }
        cout << '\n';
    }



    return 0;
}
