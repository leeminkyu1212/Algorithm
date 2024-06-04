#include <iostream>
#include <algorithm>
using namespace std;

string word[20000];


int cmp(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	else {
		return a.size() < b.size();
	}
}


int main() {
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> word[i];
	}

	sort(word, word + N, cmp);

	for (int i = 1; i <= N; i++) {
		if (word[i] == word[i - 1]) {
			continue;
		}
		cout << word[i-1] << endl;
	}

	return 0;
}
