#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(const vector<int>& requests, int N, int M, int cap) {
    int total = 0;
    for (int i = 0; i < N; i++) {
        total += min(requests[i], cap);
    }
    return total <= M;
}

int findMaxCap(const vector<int>& requests, int N, int M) {
    int left = 0;
    int right = *max_element(requests.begin(), requests.end());
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isPossible(requests, N, M, mid)) {
            result = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    int N;
    cin >> N;
    vector<int> requests(N);
    for (int i = 0; i < N; i++) {
        cin >> requests[i];
    }
    int M;
    cin >> M;

    cout << findMaxCap(requests, N, M) << endl;

    return 0;
}
