#include <iostream>
#include <queue>
using namespace std;

queue <int> q;


void init(int N) {

	for (int i = 1; i <= N; i++) {
		q.push(i);

	}
}

int main() {

	int N;
	cin >> N;
	init(N);

	for (int i = 0; i < N-1; i++) {
		q.pop();
		int temp = q.front();
		q.pop();
		q.push(temp);
	}
	cout << q.front();



}