#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int n, m;
vector<pair<int, int>> houses;
vector<pair<int, int>> chicken_shops;

int calculate_city_chicken_distance(const vector<pair<int, int>>& selected_shops) {
    int total_distance = 0;
    for (const auto& house : houses) {
        int house_r = house.first;
        int house_c = house.second;
        int min_distance = INT_MAX;
        for (const auto& shop : selected_shops) {
            int shop_r = shop.first;
            int shop_c = shop.second;
            int distance = abs(house_r - shop_r) + abs(house_c - shop_c);
            min_distance = min(min_distance, distance);
        }
        total_distance += min_distance;
    }
    return total_distance;
}

void find_minimum_chicken_distance(int index, vector<pair<int, int>>& selected_shops, int& min_distance) {
    if (selected_shops.size() == m) {
        int current_distance = calculate_city_chicken_distance(selected_shops);
        min_distance = min(min_distance, current_distance);
        return;
    }
    if (index >= chicken_shops.size()) {
        return;
    }

    selected_shops.push_back(chicken_shops[index]);
    find_minimum_chicken_distance(index + 1, selected_shops, min_distance);
    selected_shops.pop_back();

    find_minimum_chicken_distance(index + 1, selected_shops, min_distance);
}

int main() {
    cin >> n >> m;
    vector<vector<int>> city(n, vector<int>(n));

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> city[r][c];
            if (city[r][c] == 1) {
                houses.emplace_back(r, c);
            }
            else if (city[r][c] == 2) {
                chicken_shops.emplace_back(r, c);
            }
        }
    }

    int min_distance = INT_MAX;
    vector<pair<int, int>> selected_shops;

    find_minimum_chicken_distance(0, selected_shops, min_distance);

    cout << min_distance << endl;

    return 0;
}
