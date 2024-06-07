#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false; 
    if (num == 2) return true; 
    if (num % 2 == 0) return false; 

    int sqrt_num = sqrt(num);
    for (int i = 3; i <= sqrt_num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<int> numbers(N);

    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    int primeCount = 0;
    for (int i = 0; i < N; ++i) {
        if (isPrime(numbers[i])) {
            ++primeCount;
        }
    }

    cout << primeCount << endl;

    return 0;
}
