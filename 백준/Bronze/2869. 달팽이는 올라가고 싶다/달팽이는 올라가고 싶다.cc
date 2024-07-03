#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int A, B, V;
    cin >> A >> B >> V;

    int day_up = A - B;
    int days = (V - B + day_up - 1) / day_up;

    cout << days << endl;
    return 0;
}
