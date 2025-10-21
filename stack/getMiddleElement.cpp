#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int solve(stack<int> s, int pos)
{
    if (pos == 1)
    {
        return s.top();
    }
    pos--;
    int temp = s.top();
    s.pop();
    int ans = solve(s, pos);
    s.push(temp);
    return ans;
}

int getMiddleElement(stack<int> s)
{
    int size = s.size();
    if (s.empty())
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    int pos = 0;
    if (size & 1)
    {
        pos = size / 2 + 1;
    }
    else
    {
        pos = size / 2;
    }
    int ans = solve(s, pos);
    return ans;
}

int main()
{
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    cout << "Middle Element is " << getMiddleElement(s) << endl;
}