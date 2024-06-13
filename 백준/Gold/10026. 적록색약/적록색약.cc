#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
char grid[100][100];
bool visited[100][100];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y, char color, bool colorBlind) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny]) {
            if (colorBlind) {
                if ((color == 'R' || color == 'G') && (grid[nx][ny] == 'R' || grid[nx][ny] == 'G')) {
                    dfs(nx, ny, color, colorBlind);
                } else if (grid[nx][ny] == color) {
                    dfs(nx, ny, color, colorBlind);
                }
            } else {
                if (grid[nx][ny] == color) {
                    dfs(nx, ny, color, colorBlind);
                }
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int normalCount = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs(i, j, grid[i][j], false);
                normalCount++;
            }
        }
    }

    int colorBlindCount = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs(i, j, grid[i][j], true);
                colorBlindCount++;
            }
        }
    }

    cout << normalCount << " " << colorBlindCount << endl;
    return 0;
}
