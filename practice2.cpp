// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void PrintArray(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void Print2Darray(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[1].size();

    for (int i = 0; i < n; i++)
    {
        cout << "[" << " ";
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "]" << " ";
    }
}

void insertAtArray(vector<int> &arr, int k, int ele)
{
    int n = arr.size();
    arr.push_back(0);

    for (int i = n; i > k; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[k] = ele;
}
void DeleteAtArray(vector<int> &arr, int k)
{
    int n = arr.size();

    if (n == k)
    {
        arr.pop_back();
    }
    else
    {

        for (int i = k; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
    }
    arr.pop_back();
}
vector<vector<int>> TwoSum(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    int num;
    int remainingTarget;
    map<int, int> mpp;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        num = arr[i];
        remainingTarget = target - num;
        if (mpp.find(remainingTarget) != mpp.end())
        {
            ans.push_back({remainingTarget, num});
        }
        mpp[num] = i;
    }

    return ans;
}
vector<char> FindDuplicates(string &s)
{
    map<char, int> freq;
    vector<char> ans;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        freq[ch]++;
    }

    for (auto &p : freq)
    {
        if (p.second > 1)
        {
            ans.push_back(p.first);
        }
    }
    return ans;
}

vector<int> FindDuplicatesArray(vector<int> arr1)
{
    map<int, int> freq;
    vector<int> ans;
    int n = arr1.size();

    for (int i = 0; i < n; i++)
    {
        int num = arr1[i];
        freq[num]++;
    }

    for (auto &p : freq)
    {
        if (p.second > 1)
        {
            ans.push_back(p.first);
        }
    }
    return ans;
}

void intersection(vector<int> arr1, vector<int> arr2)
{

    map<int, int> freq;
    int num;
    int n = arr1.size();
    for (int i = 0; i < n; i++)
    {
        num = arr1[i];
        freq[num]++;
    }

    for (int i = 0; i < arr2.size(); i++)
    {
        num = arr2[i];
        if (freq.find(num) != freq.end())
        {
            cout << num << " ";
            freq.erase(num);
        }
    }
}

int BST(vector<int> arr1, int n, int target)
{
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr1[mid] == target)
        {
            return arr1[mid];
        }
        else if (arr1[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }

        // mid  =  (start + end) /2;
    }

    return -1;
}

int sqrt(int x)
{
    if (x == 0 || x == 1)
    {
        return x;
    }
    int s = 0;
    int e = x;
    int ans = 0;

    while (s <= e)
    {
        long long int mid = s + (e - s) / 2;
        if (mid * mid == x)
        {
            return mid;
        }
        else if (mid * mid < x)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};

    //   arr.push_back(6);
    //   PrintArray(arr);
    //   cout<<endl;
    //   insertAtArray(arr,1,0);
    //   PrintArray(arr);
    //   cout<<endl;
    //   DeleteAtArray(arr,4);
    //   PrintArray(arr);

    PrintArray(arr);
    cout << endl;
    vector<vector<int>> ans;
    ans = TwoSum(arr, 5);
    Print2Darray(ans);

    cout << endl;
    string s = "aaabbbbcde";
    vector<char> result;
    result = FindDuplicates(s);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    vector<int> arr1;
    vector<int> arr2;
    arr1 = {1, 2, 3, 4, 5, 5};
    arr2 = {1, 2, 8, 10, 7};
    vector<int> result1;
    result1 = FindDuplicatesArray(arr1);
    for (int i = 0; i < result1.size(); i++)
    {
        cout << result1[i] << " ";
    }
    cout << endl;
    intersection(arr1, arr2);

    int targetans = BST(arr1, arr1.size(), 5);
    cout << endl;
    cout << targetans;
    cout << endl;
    int sqrt1 = sqrt(10);

    cout << sqrt1 << endl;
    return 0;
}