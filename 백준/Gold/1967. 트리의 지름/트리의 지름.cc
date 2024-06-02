#include <iostream>
#include <vector>
#include <string.h>
using namespace std;



struct Node {
	int chi;
	int val;
};



int n;
vector <vector<Node>> tree;


int pre = 0;
int post = 0;
int MAX = 0;
int sum = 0;
int ans = 0;
int* visited;
int* visited2;
void func(int to) {

	int len = tree[to].size();

	if (len == 0) {
		if (sum > MAX) {
			memcpy(visited2, visited, 4 * (n + 1));
			MAX = sum;
		};

		return;
	}


	for (int i = 0; i < len; i++) {

		if (visited[tree[to][i].chi] == 1) continue;
		sum += tree[to][i].val;
		visited[tree[to][i].chi] = 1;

		func(tree[to][i].chi);

		sum -= tree[to][i].val;
		visited[tree[to][i].chi] = 0;
	}

}




int main() {


	cin >> n;
	tree.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int par, chi, val;

		cin >> par >> chi >> val;

		tree[par].push_back({ chi,val });
		//tree[chi].push_back({ par,val });
	}
	visited = new int[n + 1]{ 0 };
	visited2 = new int[n + 1]{ 0 };

	for (int i = 1; i <= n; i++) {
		pre = 0;
		post = 0;
		memset(visited, 0, 4 * (n + 1));

		visited[i] = 1;
		func(i);
		pre = max(MAX, pre);
		memcpy(visited, visited2, 4 * (n + 1));

		MAX = 0;
		sum = 0;
		func(i);
		post = max(MAX, post);

		MAX = 0;
		sum = 0;

		ans = max(ans, pre + post);
	}
	cout << ans;
}