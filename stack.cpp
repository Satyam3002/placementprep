// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Stack
{
public:
    int *arr;
    int size;
    int top;

    Stack(int size)
    {
        arr = new int[size];
        this->top = -1;
        this->size = size;
    }

    void push(int data)
    {
        if (top == size - 1)
        {
            cout << " stacker overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }

    void pop(int data)
    {
        if (top == -1)
        {
            cout << " stack underflow";
        }
        else
        {
            top--;
        }
    }

    int peek()
    {
        return arr[top];
    }
    int Getsize()
    {
        return top + 1;
    }

    void print()
    {
        for (int i = 0; i < Getsize(); i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{

    Stack st(3);
    st.push(2);
    st.push(5);
    cout << st.peek();
    cout << st.Getsize() << endl;
    st.print();

    return 0;
}