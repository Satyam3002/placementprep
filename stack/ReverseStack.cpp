#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s, int data)
{

    if (s.empty())
    {
        s.push(data);
        return;
    }
    int temp = s.top();
    s.pop();
    insertAtBottom(s, data);
    s.push(temp);
}

void reverse(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int temp = s.top();
    s.pop();
    reverse(s);

    insertAtBottom(s, temp);
}

int main()
{
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    reverse(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}