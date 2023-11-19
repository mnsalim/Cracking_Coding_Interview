#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};


struct node* newNode(int data)
{
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}
int maxValue(struct node* node)
{
    if (node == NULL) {
        return INT32_MIN;
    }
    int value = node->data;
//    cout << node->data << endl;;
    int leftMax = maxValue(node->left);
    int rightMax = maxValue(node->right);
//    cout << "left max: " <<leftMax << " rightmax = " << rightMax <<endl;
    return max(value, max(leftMax, rightMax));
}

int minValue(struct node* node)
{
    if (node == NULL) {
        return INT32_MAX;
    }
    int value = node->data;
    int leftMax = minValue(node->left);
    int rightMax = minValue(node->right);

    return min(value, min(leftMax, rightMax));
}
bool checkIsBST (struct node *root) {

    if(root == NULL)
        return true;
    if(root->left != NULL)
        if(maxValue(root -> left)>= root->data)
            return false;
    if(root -> right != NULL)
        if(minValue(root->right) <= root -> data)
            return false;

    bool left = checkIsBST(root->left);
    bool right = checkIsBST(root->right);
    return (left && right);
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

    struct node* root = newNode(5);
    root->left = newNode(1);
    root->right = newNode(4);
    root->right->left = newNode(3);
    root->right->right = newNode(6);

    std::cout << std::boolalpha;
    cout<< checkIsBST(root) <<endl;
//    maxValue(root -> right);
    return 0;
}
