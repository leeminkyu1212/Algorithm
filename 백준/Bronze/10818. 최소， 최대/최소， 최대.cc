#include <iostream>
#include <algorithm>
using namespace std;



int N;
int Max = -1000001;
int Min = 1000001;
int input;
int main() {

	cin >> N;
	while (N--) {
		cin >> input;
		Min = min(Min, input);
		Max = max(Max, input);

	}
	cout << Min << " " << Max;
}