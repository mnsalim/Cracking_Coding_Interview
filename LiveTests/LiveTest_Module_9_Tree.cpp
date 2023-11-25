#include <bits/stdc++.h>
using namespace std;

typedef struct Node Node;

struct Node {
    int value;
    Node* left, *right;
};



Node* create_node(int data) {
    Node* node = (Node*) malloc (sizeof(Node));
    node->value = data;
    node->left = node->right = NULL;
    return node;
}



int tree_height(Node* root) {

    if (!root)
        return 0;
    else {
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

int main() {


    Node* root = create_node(10);
    root->left = create_node(20);
    root->right = create_node(30);
    root->left->left = create_node(40);
    root->left->right = create_node(50);
    root->left->right->left = create_node(50);
    root->left->right->left -> left = create_node(50);


    cout << tree_height(root);


    return 0;
}
