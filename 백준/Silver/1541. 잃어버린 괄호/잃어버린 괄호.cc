#include <iostream>
#include <string>
using namespace std;

int main() {
    string expression;
    cin >> expression;

    int sum = 0;
    int current_number = 0;
    bool front_positive = true;

    for (int i = 0; i <= expression.size(); ++i) {
        if (isdigit(expression[i])) {
            current_number = current_number * 10 + (expression[i] - '0');
        }
        else {
            if (front_positive) {
                sum += current_number;
            }
            else {
                sum -= current_number;
            }
            current_number = 0;

            if (expression[i] == '-') {
                front_positive = false;
            }
        }
    }

    cout << sum;
    return 0;
}
