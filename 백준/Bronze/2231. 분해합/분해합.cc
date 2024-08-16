#include <iostream>
using namespace std;

int calculate_decomposition_sum(int number) {
    int sum = number;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    int result = 0;

    for (int i = 1; i <= n; i++) {
        if (calculate_decomposition_sum(i) == n) {
            result = i;
            break;
        }
    }

    cout << result << endl;

    return 0;
}
