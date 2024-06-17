#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> numbers;
vector<int> current;

void backtrack(int start) {
    if (current.size() == M) {
        for (int num : current) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    int last_used = -1; 
    for (int i = start; i < N; ++i) {
        if (numbers[i] != last_used) {
            current.push_back(numbers[i]);
            backtrack(i+1);  
            current.pop_back();
            last_used = numbers[i];
        }
    }
}

int main() {
    cin >> N >> M;
    numbers.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());
    backtrack(0);

    return 0;
}
