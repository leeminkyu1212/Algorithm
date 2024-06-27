#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int Max = INT_MIN;

bool alphabet[26] = { 0, };
int R, C;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };

void DFS(vector<vector<int>>& board, vector<vector<bool>>& visited, int cnt, int y, int x) {
    if (cnt > Max) Max = cnt;

    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && ny < R && nx >= 0 && nx < C && !visited[ny][nx] && !alphabet[board[ny][nx]]) {
            visited[ny][nx] = true;
            alphabet[board[ny][nx]] = true;
            DFS(board, visited, cnt + 1, ny, nx);
            visited[ny][nx] = false;
            alphabet[board[ny][nx]] = false;
        }
    }
}

int main() {
    cin >> R >> C;

    vector<vector<int>> board(R, vector<int>(C));
    vector<vector<bool>> visited(R, vector<bool>(C, 0));

    for (auto& row : board) {
        for (auto& cell : row) {
            char c;
            cin >> c;
            cell = c - 'A';
        }
    }

    visited[0][0] = true;
    alphabet[board[0][0]] = true;
    DFS(board, visited, 1, 0, 0);

    cout << Max;
}
