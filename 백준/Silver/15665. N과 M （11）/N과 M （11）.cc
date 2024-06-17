#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, M;
vector<int> numbers;
vector<int> current;
set<vector<int>> result;

void backtrack() {
    if (current.size() == M) {
        result.insert(current);
        return;
    }

    for (int i = 0; i < N; ++i) {
        current.push_back(numbers[i]);
        backtrack();
        current.pop_back();
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    numbers.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());
    backtrack();

    for (const auto& seq : result) {
        for (int num : seq) {
            cout << num << " ";
        }
        cout << '\n';
    }

    return 0;
}
