#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

int bfs(int N, int K) {
    const int MAX = 100001;
    vector<int> dist(MAX, INT_MAX);
    deque<int> dq;

    dq.emplace_back(N);
    dist[N] = 0;

    while (!dq.empty()) {
        int position = dq.front();
        dq.pop_front();
        
        // 순간이동의 경우
        if (position * 2 < MAX && dist[position * 2] > dist[position]) {
            dq.emplace_front(position * 2);
            dist[position * 2] = dist[position];
        }
        // 걷는 경우: +1
        if (position + 1 < MAX && dist[position + 1] > dist[position] + 1) {
            dq.emplace_back(position + 1);
            dist[position + 1] = dist[position] + 1;
        }
        // 걷는 경우: -1
        if (position - 1 >= 0 && dist[position - 1] > dist[position] + 1) {
            dq.emplace_back(position - 1);
            dist[position - 1] = dist[position] + 1;
        }
    }
    return dist[K];
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << bfs(N, K) << endl;
    return 0;
}
