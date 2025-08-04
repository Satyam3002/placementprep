// 1. Design a Singly Linked List and write functions to
// ○ Insert at beginning
// ○ Insert at end
// ○ Insert at any index
// ○ Delete at beginning
// ○ Delete at end
// ○ Delete at index
// ○ Delete first occurrence of node with given value
// ○ Write at least 2 test cases for each operation

#include <iostream>
using namespace std;

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
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int getLength(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    cout << "Length of the linked list is: " << count << endl;
    return count;
}
void insertAtBeginning(Node *&head, int data, Node *&tail)
{
    if (head == NULL)
    {
        /* code */
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

void insertAtEnd(Node *&head, int data, Node *&tail)

{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}
void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    int len = getLength(head);
    if (position == 1)
    {
        insertAtBeginning(head, data, tail);
    }
    else if (position > len + 1)
    {
        insertAtEnd(head, data, tail);
    }
    else
    {
        Node *newNode = new Node(data);
        Node *temp = head;
        Node *prev = NULL;
        int currPos = 1;
        while (currPos < position)
        {
            prev = temp;
            temp = temp->next;
            currPos++;
        }
        newNode->next = temp;
        prev->next = newNode;
    }
}
void DeleteAtBeginning(Node *&head, Node *&tail)
{
    if (head == NULL)
        return;
    if (head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}
void DeleteAtEnd(Node *&head, Node *&tail)
{
    if (head == NULL)
        return;
    if (head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }
    Node *prev = head;
    while (prev->next != tail)
    {
        prev = prev->next;
    }
    prev->next = NULL;
    delete tail;
    tail = prev;
}

void DeleteAtPosition(Node *&head, Node *&tail, int position)
{
    if (head == NULL)
        return;
    if (position == 1)
    {
        DeleteAtBeginning(head, tail);
        return;
    }
    int len = getLength(head);
    if (position > len)
        return;
    Node *prev = NULL;
    Node *curr = head;
    int currPos = 1;
    while (currPos < position)
    {
        prev = curr;
        curr = curr->next;
        currPos++;
    }
    prev->next = curr->next;
    if (curr == tail)
        tail = prev;
    curr->next = NULL;
    delete curr;
}

void DeleteByValue(Node *&head, Node *&tail, int value)
{
    if (head == NULL)
        return;
    if (head->data == value)
    {
        DeleteAtBeginning(head, tail);
        return;
    }
    Node *prev = head;
    Node *curr = head->next;
    while (curr != NULL)
    {
        if (curr->data == value)
        {
            prev->next = curr->next;
            if (curr == tail)
                tail = prev;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

int main()
{
    cout << "Singly Linked List operations will be implemented here." << endl;
    Node *head = NULL;
    Node *tail = NULL;

    insertAtBeginning(head, 10, tail);
    insertAtBeginning(head, 20, tail);
    print(head);
    cout << " <- after 2 inserts at beginning" << endl;

    insertAtEnd(head, 30, tail);
    insertAtEnd(head, 40, tail);
    print(head);
    cout << " <- after 2 inserts at end" << endl;

    insertAtPosition(head, tail, 25, 3);
    insertAtPosition(head, tail, 5, 1);
    print(head);
    cout << " <- after 2 inserts at position" << endl;

    DeleteAtBeginning(head, tail);
    DeleteAtBeginning(head, tail);
    print(head);
    cout << " <- after 2 deletes at beginning" << endl;

    DeleteAtEnd(head, tail);
    DeleteAtEnd(head, tail);
    print(head);
    cout << " <- after 2 deletes at end" << endl;

    insertAtEnd(head, 50, tail);
    insertAtEnd(head, 60, tail);
    insertAtEnd(head, 70, tail);
    print(head);
    cout << " <- after adding 3 more for position deletes" << endl;
    DeleteAtPosition(head, tail, 2);
    DeleteAtPosition(head, tail, 2);
    print(head);
    cout << " <- after 2 deletes at position" << endl;

    insertAtEnd(head, 80, tail);
    insertAtEnd(head, 90, tail);
    print(head);
    cout << " <- after adding 2 for value deletes" << endl;
    DeleteByValue(head, tail, 80);
    DeleteByValue(head, tail, 90);
    print(head);
    cout << " <- after 2 deletes by value" << endl;
    return 0;
}
