#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Event {
public:
    int x, height;
    bool start;

    Event(int x, int height, bool start)
        : x(x), height(height), start(start) {}
};

bool compareEvents(const Event& a, const Event& b) {
    if (a.x != b.x) return a.x < b.x;
    if (a.start != b.start) return a.start > b.start;
    return a.start ? a.height > b.height : a.height < b.height;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<Event> events;
    for (int i = 0; i < n; ++i) {
        int left, height, right;
        cin >> left >> height >> right;
        events.emplace_back(left, height, true);
        events.emplace_back(right, height, false);
    }

    sort(events.begin(), events.end(), compareEvents);

    priority_queue<int> pq; // 현재 높이들을 저장할 우선순위 큐
    unordered_map<int, int> height_count; // 높이의 유효성을 체크하기 위한 맵
    pq.push(0); // 초기 높이는 0
    vector<pair<int, int>> result;
    int previous_height = 0;

    for (const auto& event : events) {
        if (event.start) {
            pq.push(event.height);
            height_count[event.height]++;
        }
        else {
            height_count[event.height]--;
        }

        while (!pq.empty() && height_count[pq.top()] == 0) {
            pq.pop();
        }

        int current_height = pq.empty() ? 0 : pq.top();
        if (current_height != previous_height) {
            result.emplace_back(event.x, current_height);
            previous_height = current_height;
        }
    }

    for (const auto& point : result) {
        cout << point.first << " " << point.second << " ";
    }
    cout << endl;

    return 0;
}
