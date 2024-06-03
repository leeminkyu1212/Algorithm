
#include <iostream>
#include <string>
using namespace std;
int countWords(const string& input) {
    int count = 0;
    bool inWord = false;
    for (char ch : input) {
        if (isspace(ch)) {
            if (inWord) {
                inWord = false;
            }
        }
        else {
            if (!inWord) {
                inWord = true;
                ++count;
            }
        }
    }
    return count;
}

int main() {
    string input;
    getline(cin, input);
    int wordCount = countWords(input);
    cout << wordCount << endl;
    return 0;
}
