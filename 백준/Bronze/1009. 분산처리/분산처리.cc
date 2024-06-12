#include <iostream>
#include <vector>

using namespace std;

int getComputerNumber(int a, int b) {
    if (b == 0) return 1;
    
    int result = 1;
    a = a % 10;
    for (int i = 0; i < b; ++i) {
        result = (result * a) % 10;
    }
    return (result == 0) ? 10 : result;
}

int main() {

    int T;
    cin >> T;

    while (T--) {
        int a, b;
        cin >> a >> b;
        cout << getComputerNumber(a, b) << '\n';
    }

    return 0;
}
