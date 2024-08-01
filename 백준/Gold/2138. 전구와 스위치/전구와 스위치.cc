#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

using namespace std;

void toggle(vector<int>& bulbs, int index) {

    if (index > 0) bulbs[index - 1] = 1 - bulbs[index - 1];

    bulbs[index] = 1 - bulbs[index];

    if (index < bulbs.size() - 1) bulbs[index + 1] = 1 - bulbs[index + 1];

}

int countSwitches(vector<int> bulbs, vector<int> target) {

    int n = bulbs.size();

    int count = 0;

    for (int i = 1; i < n; ++i) {

        if (bulbs[i - 1] != target[i - 1]) {

            toggle(bulbs, i);

            count++;

        }

    }

    if (bulbs == target) return count;

    return -1;

}

int main() {

    int n;

    cin >> n;

    

    string current, target;

    cin >> current >> target;

    

    vector<int> bulbs(n), targetState(n);

    for (int i = 0; i < n; ++i) {

        bulbs[i] = current[i] - '0';

        targetState[i] = target[i] - '0';

    }

    vector<int> bulbsCopy = bulbs;

    int result1 = countSwitches(bulbs, targetState);

    toggle(bulbsCopy, 0);

    int result2 = countSwitches(bulbsCopy, targetState);

    if (result2 != -1) result2++;

    if (result1 == -1 && result2 == -1) {

        cout << -1 << endl;

    } else if (result1 == -1) {

        cout << result2 << endl;

    } else if (result2 == -1) {

        cout << result1 << endl;

    } else {

        cout << min(result1, result2) << endl;

    }

    return 0;

}