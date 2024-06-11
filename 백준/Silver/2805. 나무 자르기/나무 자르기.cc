#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long getWoodLength(const vector<int>& trees, int height) {
    long long total = 0;
    for (int tree : trees) {
        if (tree > height) {
            total =total+ tree - height;
        }
    }
    return total;
}

int main() {

    int N;
    long long M;
    cin >> N >> M;

    vector<int> trees(N);
    int max_height = 0;

    for (int i = 0; i < N; ++i) {
        cin >> trees[i];
        if (trees[i] > max_height) {
            max_height = trees[i];
        }
    }

    int left = 0;
    int right = max_height;
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        long long wood = getWoodLength(trees, mid);

        if (wood >= M) {
            result = mid;
            left = mid + 1; 
        }
        else {
            right = mid - 1;
        }
    }

    cout << result << '\n';

    return 0;
}
