#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long getMaxCableLength(vector<long long>& cables, int K, int N) {
    long long low = 1;
    long long high = *max_element(cables.begin(), cables.end());
    long long result = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long count = 0;

        for (int i = 0; i < K; i++) {
            count += cables[i] / mid;
        }

        if (count >= N) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int K, N;
    cin >> K >> N;

    vector<long long> cables(K);
    for (int i = 0; i < K; i++) {
        cin >> cables[i];
    }

    cout << getMaxCableLength(cables, K, N) << endl;

    return 0;
}
