#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> dp_max(2, vector<int>(3, 0));
    vector<vector<int>> dp_min(2, vector<int>(3, 0));

    for (int i = 0; i < N; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        if (i == 0) {
            dp_max[0][0] = dp_min[0][0] = a;
            dp_max[0][1] = dp_min[0][1] = b;
            dp_max[0][2] = dp_min[0][2] = c;
        } else {
            dp_max[1][0] = a + max(dp_max[0][0], dp_max[0][1]);
            dp_max[1][1] = b + max({dp_max[0][0], dp_max[0][1], dp_max[0][2]});
            dp_max[1][2] = c + max(dp_max[0][1], dp_max[0][2]);

            dp_min[1][0] = a + min(dp_min[0][0], dp_min[0][1]);
            dp_min[1][1] = b + min({dp_min[0][0], dp_min[0][1], dp_min[0][2]});
            dp_min[1][2] = c + min(dp_min[0][1], dp_min[0][2]);

            dp_max[0][0] = dp_max[1][0];
            dp_max[0][1] = dp_max[1][1];
            dp_max[0][2] = dp_max[1][2];

            dp_min[0][0] = dp_min[1][0];
            dp_min[0][1] = dp_min[1][1];
            dp_min[0][2] = dp_min[1][2];
        }
    }

    int max_score = max({dp_max[0][0], dp_max[0][1], dp_max[0][2]});
    int min_score = min({dp_min[0][0], dp_min[0][1], dp_min[0][2]});

    cout << max_score << " " << min_score << endl;

    return 0;
}
