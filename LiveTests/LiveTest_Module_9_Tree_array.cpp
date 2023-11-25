#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;


int complete_node = 6;
int tree[] = {'3', '9', '20', '\0', '\0', '15', '7'};


int get_right_child(int index)
{
    // node is not null
    // and the result must lie within the number of nodes for a complete binary tree
    if(tree[index]!='\0' && ((2*index)+1)<=complete_node)
        return (2*index)+1;
    // right child doesn't exist
    return -1;
}

int get_left_child(int index)
{
    // node is not null
    // and the result must lie within the number of nodes for a complete binary tree
    if(tree[index]!='\0' && (2*index)<=complete_node)
        return 2*index;
    // left child doesn't exist
    return -1;
}


void preorder(int index)
{
    // checking for valid index and null node
    if(index>0 && tree[index]!='\0')
    {
        printf(" %c ",tree[index]); // visiting root
        preorder(get_left_child(index)); //visiting left subtree
        preorder(get_right_child(index)); //visiting right subtree
    }
}

int tree_height(int index) {
    // Get the height of the tree
//    if (!root)
//        return 0;
    if(index == -1)
    {
        return 0;
    }
    else {
        // Find the height of both subtrees
        // and use the larger one
        int left_height = tree_height(get_left_child(index));
        int right_height = tree_height(get_right_child(index));
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

/*
Space Complexity: O(m+n)
Time Complexity: O(m+n log (m+n))

*/

int main() {
    int n;


    n = tree_height(0);

    printf("%d", n);




    return 0;
}

