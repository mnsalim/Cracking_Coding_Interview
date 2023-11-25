#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

typedef struct Node node;

void traverseList (node *start)
{
    if(start != NULL)
    {
        while(start != NULL)
        {
            cout << start->data << " ";
            start = start -> next;
        }
    }

}




node* insert_node_first(node *start, int data)
{
    node *newNode = (node *) malloc(sizeof(node)); //create a new node to insert
    newNode -> data = data; // assign data in the new node

    if(start != NULL)
    {
        newNode -> next = start;
        start = newNode;
    }
    else //for first node
    {
//        cout << "for first node" <<endl;

        start = newNode;
        start -> next = NULL;
    }

    return start;
}

node* reverseList(node *head)
{
    node* revListHead = NULL;


    while(head != NULL)
    {
        revListHead = insert_node_first(revListHead, head->data);
        head = head -> next;
    }

    return revListHead;

}

/*
Space Complexity: O(N)
Time Complexity: O(N)

*/

int main() {
    int N;
    cin >> N; //Enter how many items

    node *head = NULL;
    node *newNode = NULL, *tail = NULL;

//  take input into the linked list
    for(int i = 0; i<N; i++)
    {
        newNode = (node *)malloc(sizeof(node));
        cin >> newNode -> data;
        newNode -> next = NULL;

        if(head == NULL) //If head is null assign the first item as the head
        {
            head = newNode;
        }
        else
        {
            tail -> next = newNode;
        }

        tail = newNode;
    }



    // print the output LL
    node *current = reverseList(head);

    traverseList(current);


    return 0;
}

/*
    Input:

1
6

3
3 2 1



5
10 25 65 12 24


*/
