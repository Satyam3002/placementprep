class Solution
{
public:
    unordered_map<string, double> mp;

    double soupServings(int n)
    {
        if (n >= 4800)
            return 1.0;
        return solve(n, n);
    }

    double solve(int x, int y)
    {
        if (x <= 0 && y <= 0)
            return 0.5;
        if (x <= 0)
            return 1.0;
        if (y <= 0)
            return 0.0;

        string key = to_string(x) + "*" + to_string(y);

        if (mp.count(key))
        {
            return mp[key];
        }

        double ans = 0.25 * (solve(x - 100, y) +
                             solve(x - 75, y - 25) +
                             solve(x - 50, y - 50) +
                             solve(x - 25, y - 75));

        mp[key] = ans;
        return ans;
    }
};