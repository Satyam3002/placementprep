class Solution
{
public:
    int maximum69Number(int num)
    {

        //     string s = to_string(num);
        //     int n = s.length();
        //     for(int i=0;i<n;i++) {

        //         if(s[i]=='6') {
        //             s[i] = '9';
        //             break;
        //         }
        //     }
        //    int result = stoi(s);
        //     return result;    }

        int pos = -1, temp = num, p = 0;
        while (temp > 0)
        {
            if (temp % 10 == 6)
            {
                pos = p;
            }
            temp /= 10;
            p++;
        }

        if (pos == -1)
            return num;

        return num + 3 * pow(10, pos);
    }
};