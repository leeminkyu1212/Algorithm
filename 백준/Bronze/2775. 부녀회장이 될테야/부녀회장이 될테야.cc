#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    int apartment[15][15] = {0};

    for (int i = 1; i <= 14; i++) {
        apartment[0][i] = i;
    }

    for (int k = 1; k <= 14; k++) {
        for (int n = 1; n <= 14; n++) {
            for (int m = 1; m <= n; m++) {
                apartment[k][n] += apartment[k-1][m];
            }
        }
    }

    while (T--) {
        int k, n;
        cin >> k >> n;
        cout << apartment[k][n] << endl;
    }

    return 0;
}
