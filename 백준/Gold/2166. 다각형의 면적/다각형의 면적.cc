#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double calculatePolygonArea(const vector<Point>& points) {
    int n = points.size();
    double area = 0.0;

    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += static_cast<double>(points[i].x) * points[j].y;
        area -= static_cast<double>(points[i].y) * points[j].x;
    }

    area = abs(area) / 2.0;
    return area;
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    double area = calculatePolygonArea(points);
    cout << fixed;
    cout.precision(1);
    cout << area << endl;

    return 0;
}
