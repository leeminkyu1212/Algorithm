#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

struct Bracket {
    int open;
    int close;
};

void generateExpressions(const string& expression, const vector<Bracket>& brackets, int index, vector<bool>& toRemove, set<string>& results) {
    if (index == brackets.size()) {
        string result;
        for (int i = 0; i < expression.size(); ++i) {
            if (toRemove[i]) continue;
            result += expression[i];
        }
        if (result != expression) {
            results.insert(result);
        }
        return;
    }

    generateExpressions(expression, brackets, index + 1, toRemove, results);

    toRemove[brackets[index].open] = true;
    toRemove[brackets[index].close] = true;
    generateExpressions(expression, brackets, index + 1, toRemove, results);
    toRemove[brackets[index].open] = false;
    toRemove[brackets[index].close] = false;
}

int main() {
    string expression;
    cin >> expression;

    vector<Bracket> brackets;
    vector<int> stack;

    for (int i = 0; i < expression.size(); ++i) {
        if (expression[i] == '(') {
            stack.push_back(i);
        }
        else if (expression[i] == ')') {
            int open = stack.back();
            stack.pop_back();
            brackets.push_back({ open, i });
        }
    }

    set<string> results;
    vector<bool> toRemove(expression.size(), false);

    generateExpressions(expression, brackets, 0, toRemove, results);

    vector<string> sortedResults(results.begin(), results.end());
    sort(sortedResults.begin(), sortedResults.end());

    for (const string& result : sortedResults) {
        cout << result << '\n';
    }

    return 0;
}
