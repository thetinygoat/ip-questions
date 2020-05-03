#include <bits/stdc++.h>
#include <string>
class Solution
{
public:
    int nextGreaterElement(int n)
    {
        string num = to_string(n);
        if (num.length() >= 10)
        {
            return -1;
        }
        int d = -1;
        int i = num.length() - 2;
        while (i >= 0)
        {
            if (num[i] - '0' < num[i + 1] - '0')
            {
                d = i;
                break;
            }
            i--;
        }
        if (d == -1)
            return -1;
        int j = i + 1;
        int ng = INT_MAX;
        while (j++ < num.length())
        {
            if (num[j] - '0' > num[i] - '0' && num[j] - '0' <= ng)
            {
                ng = num[j] - '0';
            }
            else
                break;
        }
        cout << num[i] << " " << num[j];
        char temp = num[i];
        num[i] = num[j - 1];
        num[j - 1] = temp;

        int si = i + 1;
        int ei = num.length() - 1;
        while (si < ei)
        {
            temp = num[si];
            num[si] = num[ei];
            num[ei] = temp;
            si++;
            ei--;
        }

        return stoi(num);
    }
};