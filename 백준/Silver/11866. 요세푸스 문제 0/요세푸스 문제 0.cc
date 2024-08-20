#include <iostream>
#include <queue>
using namespace std;

int N, K;
queue <int> circle;
int main() {

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		circle.emplace(i);
	}
	cout << "<";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K-1; ++j) {
			int temp = circle.front();
			circle.pop();
			circle.emplace(temp);
		}
		cout << circle.front();
		if (i != N - 1) {
			cout << ", ";
		}
		circle.pop();
	}
	cout << ">";
}