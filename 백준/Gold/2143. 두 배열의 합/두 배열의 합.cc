#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // 입력 받기
    int T;
    cin >> T;

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int m;
    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    vector<int> sum_A;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += A[j];
            sum_A.push_back(sum);
        }
    }

    unordered_map<int, int> sum_B_freq;
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = i; j < m; j++) {
            sum += B[j];
            sum_B_freq[sum]++;
        }
    }

    long long result = 0;
    for (int i = 0; i < sum_A.size(); i++) {
        int target = T - sum_A[i];
        if (sum_B_freq.find(target) != sum_B_freq.end()) {
            result += sum_B_freq[target];
        }
    }

    cout << result << endl;

    return 0;
}
