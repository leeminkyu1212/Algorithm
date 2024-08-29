#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<string> map;
vector<vector<int>> visited;
int safeZoneCount = 0;

int dx[] = {-1, 1, 0, 0}; 
int dy[] = {0, 0, -1, 1};

int getDirection(char dir) {
    if (dir == 'U') return 0;
    if (dir == 'D') return 1;
    if (dir == 'L') return 2;
    if (dir == 'R') return 3;
    return -1;
}

void dfs(int x, int y, int mark) {
    visited[x][y] = mark;

    int dir = getDirection(map[x][y]);
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (visited[nx][ny] == 0) {
        dfs(nx, ny, mark);
    } else if (visited[nx][ny] == mark) {
        safeZoneCount++;
    }
}

int main() {
    cin >> n >> m;
    map.resize(n);
    visited.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }

    int mark = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == 0) { 
                dfs(i, j, mark++);
            }
        }
    }

    cout << safeZoneCount << endl;

    return 0;
}
