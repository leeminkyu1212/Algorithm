#include <iostream>
#include <vector>

using namespace std;

void fibonacci_counts(int n, vector<pair<int, int>>& fib_count) {
    fib_count[0] = { 1, 0 }; 
    fib_count[1] = { 0, 1 }; 

    for (int i = 2; i <= n; ++i) {
        fib_count[i].first = fib_count[i - 1].first + fib_count[i - 2].first;
        fib_count[i].second = fib_count[i - 1].second + fib_count[i - 2].second;
    }
}

int main() {
    int T;
    cin >> T;

    vector<int> cases(T);
    int max_n = 0;
    for (int i = 0; i < T; ++i) {
        cin >> cases[i];
        if (cases[i] > max_n) {
            max_n = cases[i];
        }
    }

    vector<pair<int, int>> fib_count(max_n + 1);
    fibonacci_counts(max_n, fib_count);

    for (int i = 0; i < T; ++i) {
        int n = cases[i];
        cout << fib_count[n].first << " " << fib_count[n].second << "\n";
    }

    return 0;
}
