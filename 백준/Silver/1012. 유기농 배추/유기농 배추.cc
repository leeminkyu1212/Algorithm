#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 51;
int T, M, N, K;
int farm[MAX][MAX] = { 0, };
bool visited[MAX][MAX] = { 0, };
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void dfs(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny] && farm[nx][ny] == 1) {
            dfs(nx, ny);
        }
    }
}

int main() {

    cin >> T;

    while (T--) {
        memset(farm, 0, sizeof(farm));
        memset(visited, 0, sizeof(visited));

        
        cin >> M >> N >> K;



        for (int i = 0; i < K; ++i) {
            int x, y;
            cin >> x >> y;
            farm[x][y] = 1;
        }

        int worm_count = 0;

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (farm[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j);
                    worm_count++;
                }
            }
        }

        cout << worm_count << endl;
    }

    return 0;
}
