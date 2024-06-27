#include <iostream>
#include <vector>

using namespace std;

void drawStars(vector<vector<char>>& map, int x, int y, int n) {
    if (n == 3) {
        map[y][x] = '*';
        map[y + 1][x - 1] = '*';
        map[y + 1][x + 1] = '*';
        map[y + 2][x - 2] = '*';
        map[y + 2][x - 1] = '*';
        map[y + 2][x] = '*';
        map[y + 2][x + 1] = '*';
        map[y + 2][x + 2] = '*';
        return;
    }

    int m = n / 2;
    drawStars(map, x, y, m);
    drawStars(map, x - m, y + m, m);
    drawStars(map, x + m, y + m, m);
}

int main() {
    int n;
    cin >> n;

    vector<vector<char>> map(n, vector<char>(2 * n - 1, ' '));
    drawStars(map, n - 1, 0, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            cout << map[i][j];
        }
        cout << '\n';
    }

    return 0;
}
