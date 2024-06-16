#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generateSequence(vector<int>& sequence, vector<int>& input, int N, int M) {
    if (sequence.size() == M) {
        for (int i = 0; i < M; ++i) {
            cout << sequence[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < N; ++i) {
        sequence.push_back(input[i]);
        generateSequence(sequence, input, N, M);
        sequence.pop_back();
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> input(N);
    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }
    sort(input.begin(), input.end());

    vector<int> sequence;
    generateSequence(sequence, input, N, M);
    return 0;
}
