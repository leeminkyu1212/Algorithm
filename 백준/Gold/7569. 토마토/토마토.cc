#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int M, N, H;
vector<vector<vector<int>>> box;
vector<vector<vector<int>>> days;
queue<tuple<int, int, int>> q;

int dz[6] = { 0, 0, 0, 0, 1, -1 };
int dy[6] = { -1, 1, 0, 0, 0, 0 };
int dx[6] = { 0, 0, -1, 1, 0, 0 };

void bfs() {
    while (!q.empty()) {
        int z, y, x;
        tie(z, y, x) = q.front();
        q.pop();

        for (int i = 0; i < 6; ++i) {
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (nz >= 0 && nz < H && ny >= 0 && ny < N && nx >= 0 && nx < M) {
                if (box[nz][ny][nx] == 0) {
                    box[nz][ny][nx] = 1;
                    days[nz][ny][nx] = days[z][y][x] + 1;
                    q.push(make_tuple(nz, ny, nx));
                }
            }
        }
    }
}

int main() {
    cin >> M >> N >> H;
    box.resize(H, vector<vector<int>>(N, vector<int>(M)));
    days.resize(H, vector<vector<int>>(N, vector<int>(M, 0)));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1) {
                    q.push(make_tuple(i, j, k));
                }
            }
        }
    }

    bfs();

    int max_days = 0;
    bool all_ripe = true;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                if (box[i][j][k] == 0) {
                    all_ripe = false;
                }
                max_days = max(max_days, days[i][j][k]);
            }
        }
    }

    if (all_ripe) {
        cout << max_days << endl;
    }
    else {
        cout << -1 << endl;
    }

    return 0;
}
