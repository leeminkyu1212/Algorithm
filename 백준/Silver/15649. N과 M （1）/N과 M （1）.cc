#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



void generateSequence(vector<int>& sequence, vector<bool>& used, int N, int M) {
	if (sequence.size() == M) {
		for (int i = 0; i < M; ++i) {
			cout << sequence[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!used[i]) {
			used[i] = true;
			sequence.push_back(i);
			generateSequence(sequence, used, N, M);
			sequence.pop_back();
			used[i] = false;
		}
	}

}


int main() {


	int M, N;
	cin >> N >> M;

	vector <int> sequence;
	vector <bool> used(N + 1, false);
	generateSequence(sequence, used, N, M);
	return 0;




}