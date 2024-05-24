#include <iostream>
#include <queue>
using namespace std;

queue <int> q;
queue<int> init(int N) {
	queue <int> q;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	return q;
}

int main() {

	int N, K;

	cin >> N >> K;

	queue <int> q = init(N);
	cout << "<";
	for (int j = 0; j < N - 1; j++) {
		for (int i = 0; i < K - 1; i++) {
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
		cout << q.front() << ", ";
		q.pop();
	}
	cout << q.front() << ">";
}