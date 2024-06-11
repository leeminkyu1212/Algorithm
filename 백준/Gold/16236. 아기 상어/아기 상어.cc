#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;


struct Shark {
    int x, y, size, eat_count;
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n;
vector<vector<int>> grid;
Shark shark;

bool bfs(Shark& shark, int& time) {
    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    q.push({shark.x, shark.y});
    dist[shark.x][shark.y] = 0;

    vector<tuple<int, int, int>> fishes; 

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1) {
                if (grid[nx][ny] <= shark.size) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});

                    if (grid[nx][ny] > 0 && grid[nx][ny] < shark.size) {
                        fishes.push_back({dist[nx][ny], nx, ny});
                    }
                }
            }
        }
    }

    if (fishes.empty()) {
        return false;
    }

    sort(fishes.begin(), fishes.end());
    int d, fx, fy;
    tie(d, fx, fy) = fishes[0];
    time += d;
    shark.x = fx;
    shark.y = fy;
    shark.eat_count++;
    if (shark.eat_count == shark.size) {
        shark.size++;
        shark.eat_count = 0;
    }
    grid[fx][fy] = 0;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    grid.assign(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 9) {
                shark = {i, j, 2, 0}; 
                grid[i][j] = 0;
            }
        }
    }

    int time = 0;
    while (bfs(shark, time)); 

    cout << time << '\n';

    return 0;
}
