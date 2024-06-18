#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paper;
int white = 0, blue = 0;

void countPapers(int x, int y, int size) {
    int color = paper[x][y];
    bool same = true;

    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (paper[i][j] != color) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same) {
        if (color == 0) white++;
        else blue++;
    }
    else {
        int newSize = size / 2;
        countPapers(x, y, newSize);
        countPapers(x + newSize, y, newSize);
        countPapers(x, y + newSize, newSize);
        countPapers(x + newSize, y + newSize, newSize);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    paper.resize(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> paper[i][j];
        }
    }

    countPapers(0, 0, N);

    cout << white << '\n' << blue << '\n';
    return 0;
}
