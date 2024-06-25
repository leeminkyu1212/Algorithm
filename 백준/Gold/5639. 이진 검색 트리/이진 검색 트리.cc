#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : key(x), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* buildTree(const vector<int>& preorder, int& index, int min, int max) {
        if (index >= preorder.size()) return nullptr;
        int key = preorder[index];
        if (key < min || key > max) return nullptr;

        TreeNode* node = new TreeNode(key);
        index++;
        node->left = buildTree(preorder, index, min, key);
        node->right = buildTree(preorder, index, key, max);
        return node;
    }

    void postOrderTraversal(TreeNode* node, vector<int>& postorder) {
        if (node == nullptr) return;
        postOrderTraversal(node->left, postorder);
        postOrderTraversal(node->right, postorder);
        postorder.push_back(node->key);
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    vector<int> preorder;
    int value;
    while (cin >> value) {
        preorder.push_back(value);
    }

    BinaryTree bt;
    int index = 0;
    TreeNode* root = bt.buildTree(preorder, index, INT_MIN, INT_MAX);

    vector<int> postorder;
    bt.postOrderTraversal(root, postorder);

    for (int key : postorder) {
        cout << key << endl;
    }

    return 0;
}
