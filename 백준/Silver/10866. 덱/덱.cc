#include <iostream>
#include <deque>
using namespace std;

int main() {


	deque <int> dq;


	string S;

	int N;
	cin >> N;
	int a;
	while (N--) {
		cin >> S;

		if (S == "push_front") {
			cin >> a;
			dq.push_front(a);
		}
		else if (S == "push_back") {
			cin >> a;
			dq.push_back(a);
		}
		else if (S == "pop_front") {
			if (dq.empty() == true) cout << -1 << endl;
			else {
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		else if (S == "pop_back") {
			if (dq.empty() == true) cout << -1 << endl;
			else {
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}
		else if (S == "size") {
			cout << dq.size() << endl;
		}
		else if (S == "empty") {
			cout << dq.empty() << endl;
		}
		else if (S == "front") {
			if (dq.empty() == true) cout << -1 << endl;
			else cout << dq.front() << endl;
		}
		else if (S == "back") {
			if (dq.empty() == true) cout << -1 << endl;
			else cout << dq.back() << endl;
		}

	}




	return 0;
}