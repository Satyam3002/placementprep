#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string s = "helllo";
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        st.push(ch);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}