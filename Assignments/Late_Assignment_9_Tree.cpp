#include <bits/stdc++.h>

using namespace std;

struct node{
    int val;
    struct node* left;
    struct node* right;
};


struct node* newNode(int data)
{
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->val = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}


struct node* searchBST (struct node *root, int val) {
    if (root == NULL || root->val == val)
        return root;
    else if(root->val < val)
        return searchBST(root->right, val);
    else
        return searchBST(root->left, val);
}



/*
    Time complexity: O(N)
    Space Complexity: O(1)
*/

int main()
{
//    struct node* root = newNode(2);
//    root->left = newNode(1);
//    root->right = newNode(3);

    struct node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->right->left = newNode(1);
    root->right->right = newNode(3);

    int val = 2;

    cout<< searchBST(root, val) <<endl;

    return 0;
}
