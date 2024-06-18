#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int result = 0;
vector<int> queen_positions;

bool isSafe(int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (queen_positions[i] == col || 
            abs(queen_positions[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solveNQueens(int row) {
    if (row == N) {
        ++result;
        return;
    }
    for (int col = 0; col < N; ++col) {
        if (isSafe(row, col)) {
            queen_positions[row] = col;
            solveNQueens(row + 1);
            queen_positions[row] = -1;
        }
    }
}

int main() {
    cin >> N;
    queen_positions.resize(N, -1);
    solveNQueens(0);
    cout << result << endl;
    return 0;
}
