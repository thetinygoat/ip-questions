#include <algorithm>
class Solution
{
public:
    string orderlyQueue(string S, int K)
    {
        if (K > 1)
        {
            sort(S.begin(), S.end());
        }
        else
        {
            string twice = S + S;
            for (int i = 1; i < S.length(); i++)
            {
                string tmp = twice.substr(i, S.length());
                S = S.compare(tmp) > 0 ? tmp : S;
            }
        }

        return S;
    }
};