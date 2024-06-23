#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countSmaller(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int count = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) {
            count = mid + 1;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A(N), B(M);
        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 0; i < M; i++) cin >> B[i];
        
        sort(B.begin(), B.end());
        
        int totalCount = 0;
        for (int i = 0; i < N; i++) {
            totalCount += countSmaller(B, A[i]);
        }
        
        cout << totalCount << endl;
    }
    return 0;
}
