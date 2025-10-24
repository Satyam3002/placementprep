class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {

        long long MinSum = sumSubarrayMins(nums);
        long long MaxSum = sumSubarrayMax(nums);
        return (MaxSum - MinSum);
    }

    long long sumSubarrayMax(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prev(n);
        vector<int> next(n);
        prev = prev_max(arr, n);
        next = next_max(arr, n);
        long long sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            long long left = i - prev[i];
            long long right = next[i] - i;
            sum = (sum + (left * right * arr[i]));
        }

        return sum;
    }
    vector<int> prev_max(vector<int> &arr, int n)
    {
        stack<int> s;
        vector<int> ans(n, 0);

        for (int i = 0; i < arr.size(); i++)
        {
            while (!s.empty() && arr[s.top()] < arr[i])
            {
                s.pop();
            }

            if (s.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = s.top();
            }
            s.push(i);
        }

        return ans;
    }

    vector<int> next_max(vector<int> &arr, int n)
    {
        stack<int> s;
        vector<int> ans(n, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && arr[s.top()] <= arr[i])
            {
                s.pop();
            }

            if (s.empty())
            {
                ans[i] = n;
            }
            else
            {
                ans[i] = s.top();
            }
            s.push(i);
        }

        return ans;
    }

    long long sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prev(n);
        vector<int> next(n);
        prev = prev_smaller(arr, n);
        next = next_smaller(arr, n);
        long long sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            long long left = i - prev[i];
            long long right = next[i] - i;
            sum = (sum + (left * right * arr[i]));
        }

        return sum;
    }

    vector<int> prev_smaller(vector<int> &arr, int n)
    {
        stack<int> s;
        vector<int> ans(n, 0);

        for (int i = 0; i < arr.size(); i++)
        {
            while (!s.empty() && arr[s.top()] > arr[i])
            {
                s.pop();
            }

            if (s.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = s.top();
            }
            s.push(i);
        }

        return ans;
    }

    vector<int> next_smaller(vector<int> &arr, int n)
    {
        stack<int> s;
        vector<int> ans(n, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
            {
                s.pop();
            }

            if (s.empty())
            {
                ans[i] = n;
            }
            else
            {
                ans[i] = s.top();
            }
            s.push(i);
        }

        return ans;
    }
};