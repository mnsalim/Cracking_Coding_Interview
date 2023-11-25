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




void insert_node_middle(node *prev, node* dataVal)
{
    node *nextNodeLink;

    if(prev != NULL)
    {
        nextNodeLink = dataVal -> next;   //save prev node link
        prev -> next = dataVal;
        dataVal -> next = prev -> next;
    }
}


node* reverseSelected(node *head, int leftInd, int rightInd)
{
    node* revListHead = head;
    node* revSel = NULL, *temp = NULL;
    int count = 1;


    cout <<"revListHead data " << revListHead ->data <<endl;
    while(head != NULL)
    {
        if(head -> next != NULL)
        {
            count++;
            cout << "Val of count " << count <<endl;
            if(count == leftInd)
                revSel = head;
            if(count > leftInd && count <= rightInd)
            {
                cout << "insert middle called with " << head->next->data <<endl;
                temp = head-> next -> next;
                insert_node_middle(revSel, head->next);
                head ->next = temp;
            }
        }
        head = head->next;
    }

    return revListHead;

}

int main() {
    int N, left, right;
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


    cout <<"Head data " << head ->data <<endl;
    cin >> left >> right;

    // print the output LL
    node *current = reverseSelected(head, left, right);

//    traverseList(current);


    return 0;
}

/*
    Input:

5
1 2 3 4 5
2 4

*/
