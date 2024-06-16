#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void generateSequence(vector<int>& sequence, vector<int>& input, vector<bool>& used, int N, int M) {
	if (sequence.size() == M) {
		for (int i = 0; i < M; ++i) {
			cout << sequence[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!used[i]) {
			used[i] = true;
			sequence.push_back(input[i]);
			generateSequence(sequence, input, used, N, M);
			sequence.pop_back();
			used[i] = false;
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> input(N);
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	sort(input.begin(), input.end());

	vector <int> sequence;
	vector <bool> used(N, false);
	generateSequence(sequence, input, used, N, M);
	return 0;
}
