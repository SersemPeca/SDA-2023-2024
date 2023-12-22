#include <algorithm>
#include <iostream>
#include <limits.h>
#include <cstddef>

#define PII pair<int, int>

using namespace std;


struct Node {
    
    int val;

    Node* left, *right;

    Node() {
        this->val = INT_MIN;
        this->left = NULL;
        this->right= NULL;
    }

    Node(int val) {

        this->val = val;
        this->left = NULL;
        this->right= NULL;
    }

    Node(int val, Node* left, Node* right) {

        this->val = val;
        this->left = left;
        this->right= right;
    }

};

int heightOfTree(Node* curr) {

    if (curr == NULL) {
        return 0;
    }

    int left = heightOfTree(curr->left);
    int right = heightOfTree(curr->right);

    int ans = max(left, right) + 1;

    return ans;
}

PII dfs(Node* curr) {
    
    if (curr == NULL) {
        return { 0, INT_MIN };
    }

    PII left = dfs(curr->left);
    PII right = dfs(curr->right);

    int ans = max(left.second, right.second);

}

int main() {
    
    //Node* root(10, Node(1, Node(3, Node(4, NULL, NULL), NULL), NULL), Node(2, NULL, Node(11, NULL, NULL)));

    Node* root = new Node(10, new Node(1, new Node(-2, NULL, NULL), NULL), new Node(2, NULL, NULL));

    PII ans = dfs(root);

    cout << ans.second << '\n';

}
