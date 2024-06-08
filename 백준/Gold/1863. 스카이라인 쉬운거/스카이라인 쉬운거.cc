#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector <pair<int, int>> skyline;
stack <int> heights;
int building_cnt=0;
int main() {

	int n;
	cin >> n;
	skyline.reserve(n);

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		skyline.emplace_back(x, y);
	}
	
	for (int i = 0; i < n; i++) {
		int current_height = skyline[i].second;
		while (!heights.empty() && heights.top() > current_height) {
			heights.pop();
		}
		if (heights.empty() || heights.top() < current_height) {
			heights.push(current_height);
			if (current_height != 0) {
				++building_cnt;
			}
		}
	}
	cout << building_cnt << endl;
}