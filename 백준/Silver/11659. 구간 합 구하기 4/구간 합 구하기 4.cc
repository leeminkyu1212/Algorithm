#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> numbers(N + 1, 0);
    vector<int> prefix_sum(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        cin >> numbers[i];
        prefix_sum[i] = prefix_sum[i - 1] + numbers[i];
    }

    for (int q = 0; q < M; ++q) {
        int i, j;
        cin >> i >> j;
        cout << prefix_sum[j] - prefix_sum[i - 1] << '\n';
    }

    return 0;
}
