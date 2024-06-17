#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {


    int N;
    cin >> N;
    vector<int> original(N);
    vector<int> sorted(N);

    for (int i = 0; i < N; ++i) {
        cin >> original[i];
        sorted[i] = original[i];
    }

    sort(sorted.begin(), sorted.end());

    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    unordered_map<int, int> compress;
    for (int i = 0; i < sorted.size(); ++i) {
        compress[sorted[i]] = i;
    }

    for (int i = 0; i < N; ++i) {
        cout << compress[original[i]] << " ";
    }
    cout << '\n';

    return 0;
}
