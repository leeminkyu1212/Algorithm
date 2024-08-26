#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        
        if (x != 0) {
            pq.push({abs(x), x});
        } else {
            if (pq.empty()) {
                cout << "0\n";
            } else {
                cout << pq.top().second << "\n";
                pq.pop();
            }
        }
    }
    
    return 0;
}
