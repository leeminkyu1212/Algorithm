#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> findNGE(const vector<int>& A) {
    int N = A.size();
    vector<int> result(N, -1); 
    stack<int> s;
    
    for (int i = 0; i < N; ++i) {
        while (!s.empty() && A[s.top()] < A[i]) {
            result[s.top()] = A[i];
            s.pop(); 
        }
        s.push(i);
    }
    
    return result;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<int> result = findNGE(A);
    
    for (int i = 0; i < N; ++i) {
        cout << result[i];
        if (i != N - 1) cout << " ";
    }
    
    return 0;
}
