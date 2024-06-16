#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateSequence(vector<int>& sequence, int start, int N, int M) {
    if (sequence.size() == M) {
        for (int i = 0; i < M; ++i) {
            cout << sequence[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = start; i <= N; i++) {
        sequence.push_back(i);
        generateSequence(sequence, i + 1, N, M);
        sequence.pop_back();
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> sequence;
    generateSequence(sequence, 1, N, M);
    return 0;
}
