#include <iostream>
#include <vector>
using namespace std;

int sum = 0;
int Max = 0;
int N, M;
vector<int> cards;

void func(int index, int level) {
    if (level == 3) {
        if (sum <= M && sum > Max) {
            Max = sum;
        }
        return;
    }

    for (int i = index + 1; i < N; ++i) {
        sum += cards[i];
        func(i, level + 1);
        sum -= cards[i];
    }
}

int main() {
    cin >> N >> M;
    cards.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> cards[i];
    }

    for (int i = 0; i < N; ++i) {
        sum += cards[i];
        func(i, 1);
        sum -= cards[i];
    }

    cout << Max << endl;

    return 0;
}
