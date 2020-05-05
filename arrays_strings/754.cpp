#include <bits/stdc++.h>
class Solution
{
public:
    int reachNumber(int target)
    {
        long int jumps = 0;
        long int i = 1;
        long int t = abs(target);
        while (true)
        {
            if (t <= 0)
                break;
            t -= i;
            i++;
            jumps++;
        }
        if (t < 0)
        {
            t = abs(t);
            while (t % 2 != 0)
            {
                t -= i;
                jumps++;
                i++;
            }
        }
        return jumps;
    }
};