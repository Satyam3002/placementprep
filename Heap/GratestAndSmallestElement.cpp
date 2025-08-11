#include <iostream>
using namespace std;
#include <queue>

int getKthGreatestElement(int arr[], int n, int k)
{
    // create min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    // insert initial k elements of array
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // for remaining elements, push only if they are greater than top
    for (int i = k; i < n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}
int getKthSmallestElement(int arr[], int n, int k)
{
    // create max heap
    priority_queue<int> pq;
    // insert initial k elements of array
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    // for remaining elements, push only if they are less than top
    for (int i = k; i < n; i++)
    {
        if (arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int main()
{
    int arr[] = {10, 5, 20, 4, 15};
    int n = 5;
    int k = 3;
    int ans = getKthGreatestElement(arr, n, k);
    cout << "The " << k << "th greatest element is: " << ans << endl;
    ans = getKthSmallestElement(arr, n, k);
    cout << "The " << k << "th smallest element is: " << ans << endl;
    return 0;
}
