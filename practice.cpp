
#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void inserAtHead(Node *&head, int val, Node *&tail)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void PrintLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    inserAtHead(head, 10, tail);
    inserAtHead(head, 5, tail);
    inserAtHead(head, 3, tail);
    inserAtHead(head, 1, tail);

    PrintLL(head);
    return 0;
}