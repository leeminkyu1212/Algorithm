#include <iostream>
using namespace std;

long long func(long long a, long long b, long long c) {
    if (b == 0)
        return 1;
    long long half = func(a, b / 2, c);
    long long result = (half * half) % c;
    if (b % 2 != 0) {
        result = (result * a) % c;
    }
    return result;
}

int main() {
    long long A, B, C;
    cin >> A >> B >> C;
    cout << func(A, B, C) << endl;
    return 0;
}
