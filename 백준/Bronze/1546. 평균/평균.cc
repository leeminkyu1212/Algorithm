
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> scores(N);
    for (int i = 0; i < N; ++i) {
        cin >> scores[i];
    }

    int max_score = *max_element(scores.begin(), scores.end());

    double sum_new_scores = 0.0;
    for (int i = 0; i < N; ++i) {
        sum_new_scores += (static_cast<double>(scores[i]) / max_score) * 100;
    }

    double new_average = sum_new_scores / N;

    cout.precision(10);
    cout << new_average << endl;

    return 0;
}
