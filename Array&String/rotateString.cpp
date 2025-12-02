class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        // if (s.size() != goal.size()) return false;
        // int n = s.size();
        // for(int i =0;i<n;i++) {
        //     char temp = s[0];
        //     s = s.substr(1);
        //     s.push_back(temp);
        //     if(s == goal ) {
        //         return true;
        //     }
        // }

        // return false;
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};