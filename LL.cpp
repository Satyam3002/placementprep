// Online C++ compiler to run C++ program online

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
    Node *NewNode = new Node(val);
    // if LL empty
    if (head == NULL)
    {
        head = NewNode;
        tail = NewNode;
    }
    else
    {
        NewNode->next = head;
        head = NewNode;
    }
}

void insertAtTail(Node *&head, int val, Node *&tail)
{
    Node *NewNode = new Node(val);
    if (head == NULL)
    {
        head = NewNode;
        tail = NewNode;
    }
    else
    {
        tail->next = NewNode;
        tail = NewNode;
    }
}

void PrintLL(Node *&head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int LengthLL(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}
void insertAtPosition(Node *&head, int val, Node *&tail, int k)
{

    int length = LengthLL(head);

    if (k == 1)
    {
        inserAtHead(head, val, tail);
    }
    else if (k >= length)
    {
        insertAtTail(head, val, tail);
    }
    else
    {

        Node *NewNode = new Node(val);
        Node *prev = NULL;
        Node *curr = head;
        while (k != 1)
        {
            k--;
            prev = curr;
            curr = curr->next;
        }

        prev->next = NewNode;
        NewNode->next = curr;
    }
}

void DeleteAtPosition(Node *&head, Node *&tail, int k)
{

    if (head == tail)
    {
        Node *temp = head;
        delete head;
        head = NULL;
        tail = NULL;
    }
    if (head == NULL)
    {
        cout << "LL is Empty " << endl;
    }

    int length = LengthLL(head);
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else if (k == length)
    {
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    else
    {
        Node *prev = NULL;
        Node *curr = head;
        while (k != 1)
        {
            k--;
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

Node *middleNode(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    return slow;
}

Node *ReverseLL(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    inserAtHead(head, 5, tail);
    inserAtHead(head, 50, tail);
    inserAtHead(head, 10, tail);
    inserAtHead(head, 15, tail);
    insertAtTail(head, 1, tail);
    insertAtTail(head, 100, tail);

    PrintLL(head);
    cout << endl;
    LengthLL(head);
    cout << endl;

    insertAtPosition(head, 5, tail, 2);
    PrintLL(head);

    cout << endl;
    int length = LengthLL(head);
    cout << length << endl;

    DeleteAtPosition(head, tail, 1);
    cout << "After Deleting" << endl;
    PrintLL(head);
    cout << "After Deleting" << endl;
    DeleteAtPosition(head, tail, 5);
    PrintLL(head);

    Node *ans = middleNode(head);
    cout << "middle of LL" << endl;
    cout << ans->data << " ";
    head = ReverseLL(head);
    cout << "Reverse of LL" << endl;
    PrintLL(head);

    return 0;
}