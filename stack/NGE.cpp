// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <bits/stdc++.h>

vector<int> nge(int arr[], int n)
{
    vector<int> result(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            result[i] = -1;
        }
        else
        {
            result[i] = st.top();
        }
        st.push(arr[i]);
    }
    return result;
}
int main()
{
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> result = nge(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}