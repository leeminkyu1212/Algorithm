#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> preorder;
vector<int> inorder;
unordered_map<int, int> inorder_index;

void buildPostorder(int preStart, int preEnd, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd) return;

    int root = preorder[preStart];
    int rootIndexInorder = inorder_index[root];
    int leftTreeSize = rootIndexInorder - inStart;

    buildPostorder(preStart + 1, preStart + leftTreeSize, inStart, rootIndexInorder - 1);

    buildPostorder(preStart + leftTreeSize + 1, preEnd, rootIndexInorder + 1, inEnd);

    cout << root << " ";
}

int main() {

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        preorder.resize(n);
        inorder.resize(n);
        inorder_index.clear();

        for (int i = 0; i < n; ++i) {
            cin >> preorder[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> inorder[i];
            inorder_index[inorder[i]] = i;
        }

        buildPostorder(0, n - 1, 0, n - 1);
        cout << "\n";
    }

    return 0;
}
