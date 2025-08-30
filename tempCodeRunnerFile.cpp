#include <iostream>
using namespace std;

int FindFactorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}
int FindNcR(int n, int r)
{
    int Mindex = n - r;
    int numerator = 1;
    int denominator = 1;
    while (Mindex <= n)
    {
        numerator *= Mindex;
        Mindex++;
    }
    denominator = FindFactorial(r);
    return numerator / denominator;
}

int main()
{
    int n, r;
    cin >> n >> r;
    cout << FindNcR(n, r);
    return 0;
}
