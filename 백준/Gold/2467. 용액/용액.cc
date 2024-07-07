#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int left = 0;
    int right = N - 1;
    int closest_sum = arr[left] + arr[right];
    int ans_left = arr[left];
    int ans_right = arr[right];

    while (left < right) {
        int current_sum = arr[left] + arr[right];
        
        if (abs(current_sum) < abs(closest_sum)) {
            closest_sum = current_sum;
            ans_left = arr[left];
            ans_right = arr[right];
        }
        
        if (current_sum < 0) {
            ++left;
        }
        else if (current_sum > 0) {
            --right;
        }
        else {
            break;
        }
    }

    cout << ans_left << " " << ans_right << endl;

    return 0;
}
