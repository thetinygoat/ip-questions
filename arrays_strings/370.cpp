#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> rangeAddition(int n, vector<vector<int>> queries)
{
    vector<int> ans(n + 1, 0);
    if (queries.size() == 0)
        return ans;
    vector<int> prefix(n, 0);
    for (vector<int> q : queries)
    {
        int si = q[0];
        int ei = q[1] + 1;
        int inc = q[2];
        ans[si] += inc;
        ans[ei] += -inc;
    }

    for (int i = 0; i < prefix.size(); i++)
    {
        if (i == 0)
        {
            prefix[i] = ans[i];
        }
        else
        {
            prefix[i] = ans[i] + prefix[i - 1];
        }
    }

    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> q = {{1, 3, 2},
                             {2, 4, 3},
                             {0, 2, -2}};
    rangeAddition(n, q);

    return 0;
}