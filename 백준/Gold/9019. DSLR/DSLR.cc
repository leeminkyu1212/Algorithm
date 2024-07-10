#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// 명령어들을 정의합니다.
struct Command {
    int value;
    string path;
};

int D(int n) {
    return (2 * n) % 10000;
}

int S(int n) {
    return (n == 0) ? 9999 : n - 1;
}

int L(int n) {
    return (n % 1000) * 10 + n / 1000;
}

int R(int n) {
    return (n % 10) * 1000 + n / 10;
}

string bfs(int start, int target) {
    queue<Command> q;
    vector<bool> visited(10000, false);
    q.push({start, ""});
    visited[start] = true;
    
    while (!q.empty()) {
        Command current = q.front();
        q.pop();
        
        if (current.value == target) {
            return current.path;
        }
        
        int nextValue = D(current.value);
        if (!visited[nextValue]) {
            q.push({nextValue, current.path + "D"});
            visited[nextValue] = true;
        }
        
        nextValue = S(current.value);
        if (!visited[nextValue]) {
            q.push({nextValue, current.path + "S"});
            visited[nextValue] = true;
        }
        
        nextValue = L(current.value);
        if (!visited[nextValue]) {
            q.push({nextValue, current.path + "L"});
            visited[nextValue] = true;
        }
        
        nextValue = R(current.value);
        if (!visited[nextValue]) {
            q.push({nextValue, current.path + "R"});
            visited[nextValue] = true;
        }
    }
    return "";
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int A, B;
        cin >> A >> B;
        cout << bfs(A, B) << endl;
    }
    
    return 0;
}
