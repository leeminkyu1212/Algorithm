#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, B;
    cin >> N >> M >> B;

    vector<vector<int>> land(N, vector<int>(M)); //땅
    int min_height = 256, max_height = 0; //최대최소

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> land[i][j];
            min_height = min(min_height, land[i][j]);
            max_height = max(max_height, land[i][j]);
        }
    }

    int min_time = 200000000;
    int best_height = -1;

    for (int target_height = min_height; target_height <= max_height; ++target_height) {
        int time = 0;
        int blocks_needed = 0;
        int blocks_removed = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int diff = land[i][j] - target_height;
                if (diff > 0) {
                    blocks_removed += diff;
                    time += diff * 2;
                }
                else if (diff < 0) {
                    blocks_needed -= diff;
                    time -= diff;
                }
            }
        }

        if (blocks_removed + B >= blocks_needed) {
            if (time < min_time || (time == min_time && target_height > best_height)) {
                min_time = time;
                best_height = target_height;
            }
        }
    }

    cout << min_time << " " << best_height << endl;

    return 0;
}
