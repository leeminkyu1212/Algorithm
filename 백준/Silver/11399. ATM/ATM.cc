#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    sort(p.begin(), p.end());

    int total_time = 0;
    int accumulated_time = 0;
    for (int i = 0; i < n; ++i) {
        accumulated_time += p[i];
        total_time += accumulated_time;
    }

    cout << total_time << endl;

    return 0;
}
