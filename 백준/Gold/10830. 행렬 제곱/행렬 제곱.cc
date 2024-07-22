#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000;

vector<vector<int>> multiplyMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B, int N) {
    vector<vector<int>> result(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return result;
}

vector<vector<int>> matrixPower(vector<vector<int>>& A, long long B, int N) {
    vector<vector<int>> result(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        result[i][i] = 1;
    }

    while (B > 0) {
        if (B % 2 == 1) {
            result = multiplyMatrix(result, A, N);
        }
        A = multiplyMatrix(A, A, N);
        B /= 2;
    }

    return result;
}

int main() {
    int N;
    long long B;
    cin >> N >> B;

    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<int>> result = matrixPower(A, B, N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
