#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int N, M;
vector<vector<int>> maze;
vector<vector<bool>> visited;
vector<vector<int>> Distance;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void bfs(int start_x, int start_y) {
    queue<pair<int, int>> q;
    q.emplace(start_x, start_y);
    visited[start_x][start_y] = true;
    Distance[start_x][start_y] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (maze[nx][ny] == 1 && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    Distance[nx][ny] = Distance[x][y] + 1;
                    q.emplace(nx, ny);
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;

    maze.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M, false));
    Distance.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < M; ++j) {
            maze[i][j] = row[j] - '0';
        }
    }

    bfs(0, 0);

    cout << Distance[N - 1][M - 1] << endl;

    return 0;
}
