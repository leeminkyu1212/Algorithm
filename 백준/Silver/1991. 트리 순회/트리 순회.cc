// main.cpp

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

unordered_map<char, Node*> nodes;

void preorder(Node* node) {
    if (node == nullptr) return;
    cout << node->data;
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node) {
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->data;
    inorder(node->right);
}

void postorder(Node* node) {
    if (node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        char parent, left, right;
        cin >> parent >> left >> right;
        if (nodes.find(parent) == nodes.end()) {
            nodes[parent] = new Node(parent);
        }
        if (left != '.') {
            nodes[left] = new Node(left);
            nodes[parent]->left = nodes[left];
        }
        if (right != '.') {
            nodes[right] = new Node(right);
            nodes[parent]->right = nodes[right];
        }
    }

    Node* root = nodes['A'];

    preorder(root);
    cout << endl;

    inorder(root);
    cout << endl;

    postorder(root);
    cout << endl;

    return 0;
}
