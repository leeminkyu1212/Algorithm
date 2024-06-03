#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define MAX 102

using namespace std;

int map[MAX][MAX];
bool check[MAX][MAX];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int num = 1, n;
queue<pair<int, int>> q;
vector<pair<int, int>> island_map;

int bfs(int x, int y) {
    int dist[MAX][MAX] = { 0, };
    int min_dist = 1e8;
    q.push({ x, y });
    dist[x][y] = 0;

    while (!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (dist[nx][ny] != 0) continue;
            if (map[nx][ny] == map[x][y]) continue;
            if (map[nx][ny] != map[x][y] && map[nx][ny] != 0) {
                min_dist = min(min_dist, dist[cur.first][cur.second]);
                continue;
            }

            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({ nx, ny });
        }
    }

    return min_dist;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1 && !check[i][j]) {
                q.push({ i, j });
                check[i][j] = true;
                map[i][j] = num;

                while (!q.empty()) {
                    pair<int,int> cur = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (check[nx][ny]) continue;
                        if (map[nx][ny] == 0) {
                            island_map.push_back({ cur.first, cur.second });
                            continue;
                        }

                        check[nx][ny] = true;
                        map[nx][ny] = num;
                        q.push({ nx, ny });
                    }
                }
                num++;
            }
        }
    }

    sort(island_map.begin(), island_map.end());
    island_map.erase(unique(island_map.begin(), island_map.end()), island_map.end());

    int result_dist = 1e9;
    for (int i = 0; i < island_map.size(); i++) {
        result_dist = min(result_dist, bfs(island_map[i].first, island_map[i].second));
    }

    cout << result_dist;
    return 0;
}
