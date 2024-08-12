#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool comparePoints(const Point& a, const Point& b) {
    if (a.x == b.x) {
        return a.y < b.y;
    } else {
        return a.x < b.x;
    }
}

int main() {
    int N;
    cin >> N;
    
    vector<Point> points(N);
    
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    sort(points.begin(), points.end(), comparePoints);
    
    for (const auto& point : points) {
        cout << point.x << " " << point.y << '\n';
    }
    
    return 0;
}
