#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 500;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int N, M;
int board[MAX][MAX];
bool visited[MAX][MAX];

int dfs(int x, int y, int depth) {
    if (depth == 3) {
        return board[x][y];
    }
    
    int maxSum = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny]) {
            visited[nx][ny] = true;
            maxSum = max(maxSum, board[x][y] + dfs(nx, ny, depth + 1));
            visited[nx][ny] = false;
        }
    }
    return maxSum;
}

int getMaxWOOShape(int x, int y) {
    int maxSum = 0;
    if (x >= 1 && y >= 1 && y + 1 < M) { // ㅗ
        int sum = board[x][y] + board[x-1][y] + board[x][y-1] + board[x][y+1];
        maxSum = max(maxSum, sum);
    }
    if (x + 1 < N && y >= 1 && y + 1 < M) { // ㅜ
        int sum = board[x][y] + board[x+1][y] + board[x][y-1] + board[x][y+1];
        maxSum = max(maxSum, sum);
    }
    if (x >= 1 && x + 1 < N && y >= 1) { // ㅏ
        int sum = board[x][y] + board[x-1][y] + board[x+1][y] + board[x][y-1];
        maxSum = max(maxSum, sum);
    }
    if (x >= 1 && x + 1 < N && y + 1 < M) { // ㅓ
        int sum = board[x][y] + board[x-1][y] + board[x+1][y] + board[x][y+1];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = true;
            answer = max(answer, dfs(i, j, 0));
            visited[i][j] = false;
            answer = max(answer, getMaxWOOShape(i, j));
        }
    }

    cout << answer << "\n";
    return 0;
}
