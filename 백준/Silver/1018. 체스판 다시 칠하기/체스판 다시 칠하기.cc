#include <iostream>

using namespace std;

char board[51][51];

int Min = 200000000;
void whiteFirst(int row,int col) {

	int cnt = 0;
	for (int i = row; i < row + 8; i++) {
		for (int j = col; j < col + 8; j++) {
			if ((j + i) % 2 == 0 && board[i][j] == 'B') cnt++;
			if ((j + i) % 2 == 1 && board[i][j] == 'W') cnt++;
		}
	}

	Min = min(cnt, Min);
}
void blackFirst(int row, int col) {

	int cnt = 0;
	for (int i = row; i < row + 8; i++) {
		for (int j = col; j < col + 8; j++) {
			if ((j + i) % 2 == 0 && board[i][j] == 'W') cnt++;
			if ((j + i) % 2 == 1 && board[i][j] == 'B') cnt++;
		}
	}

	Min = min(cnt, Min);
}


int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			whiteFirst(i, j);
			blackFirst(i, j);
		}
	}

	cout << Min;
}