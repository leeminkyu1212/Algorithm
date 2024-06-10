#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 300;
int n;
int scores[MAX + 1];

int memo[MAX + 1][3];

int dfs(int step, int prevStepCount) {
    if (step == 0) return scores[0];
    if (step < 0) return 0;

    if (memo[step][prevStepCount] != -1) return memo[step][prevStepCount];

    int takeOneStep = 0;
    int takeTwoSteps = 0;

    if (prevStepCount < 2) {
        takeOneStep = scores[step] + dfs(step - 1, prevStepCount + 1);
    }

    takeTwoSteps = scores[step] + dfs(step - 2, 1);

    memo[step][prevStepCount] = max(takeOneStep, takeTwoSteps);
    return memo[step][prevStepCount];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> scores[i];
    }

    fill(&memo[0][0], &memo[0][0] + sizeof(memo) / sizeof(memo[0][0]), -1);

    cout << dfs(n - 1, 1) << endl;

    return 0;
}
