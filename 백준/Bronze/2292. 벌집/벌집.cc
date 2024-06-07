#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;

    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }

    int layer = 1;
    long long max_number_in_layer = 1;

    while (max_number_in_layer < N) {
        max_number_in_layer += 6 * layer;
        layer++;
    }

    cout << layer << endl;
    return 0;
}
