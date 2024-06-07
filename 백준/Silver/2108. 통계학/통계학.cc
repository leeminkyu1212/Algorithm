#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> numbers(N);
    int sum = 0;
    int max_value = INT_MIN;
    int min_value = INT_MAX;
    map<int, int> frequency;

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        numbers[i] = num;
        sum += num;
        max_value = max(max_value, num);
        min_value = min(min_value, num);
        frequency[num]++;
    }

    double mean = (double)(sum) / N;
    cout << (int)(round(mean)) << endl;

    sort(numbers.begin(), numbers.end());
    cout << numbers[N / 2] << endl;

    int max_freq = 0;
    vector<int> modes;
    for (const auto& kv : frequency) {
        if (kv.second > max_freq) {
            max_freq = kv.second;
            modes = { kv.first };
        }
        else if (kv.second == max_freq) {
            modes.push_back(kv.first);
        }
    }
    sort(modes.begin(), modes.end());
    cout << (modes.size() > 1 ? modes[1] : modes[0]) << endl;

    int range = max_value - min_value;
    cout << range << endl;

    return 0;
}
