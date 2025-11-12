#include <iostream>
using namespace std;
#include <bits/stdc++.h>

string revisedstring(string x)

{
    int n = x.size();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == '#')
        {
            if (!st.empty())
                st.pop();
        }
        else
        {
            st.push(x[i]);
        }
    }
    string ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());

    return ans;
}
bool backspaceCompare(string s, string t)
{
    string temp1 = revisedstring(s);
    string temp2 = revisedstring(t);

    return temp1 == temp2;
}

int main()
{
    string s = "ab#c";
    string t = "ad#c";
    cout << backspaceCompare(s, t);
    return 0;
}