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

bool checkIsBST (struct node *root) {

    if(root == NULL)
        return true;
    if(root->left != NULL)
        if(root -> left -> data >= root->data)
            return false;
    if(root -> right != NULL)
        if(root->right->data <= root -> data)
            return false;

    bool left = checkIsBST(root->left);
    bool right = checkIsBST(root->right);
    return (left && right);
}



/*
    Time complexity: O(V * E) where V = noOfNodes, E= noOfEdges;
    Space Complexity: O(V+E)
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
    return 0;
}
