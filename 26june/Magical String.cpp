class Solution
{
public:
    int magicalString(int n)
    {
        if (n == 0)
            return 0;
        if (n <= 3)
            return 1;

        vector<int> s(n + 1);
        s[0] = 1;
        s[1] = 2;
        s[2] = 2;

        int head = 2;  // Points to the index in s that tells how many times to write the next number
        int tail = 3;  // Points to the next index to write in s
        int num = 1;   // The current number to write (either 1 or 2)
        int count = 1; // We've already seen one '1' in s[0..2]

        while (tail < n)
        {
            int times = s[head]; // Either 1 or 2
            for (int i = 0; i < times && tail < n; ++i)
            {
                s[tail] = num;
                if (num == 1)
                    ++count;
                ++tail;
            }
            num = 3 - num; // Switch between 1 and 2
            ++head;
        }

        return count;
    }
};