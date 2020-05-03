#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxrangequeries(int size, vector<vector<int>> queries, int k)
{
    vector<int> cakes(size + 1, 0);
    for (vector<int> q : queries)
    {
        int si = q[0] - 1;
        int ei = q[1];
        int inc = 1;
        cakes[si] += inc;
        cakes[ei] += -inc;
    }
    vector<int> prefix(cakes.size(), 0);
    prefix[0] = cakes[0];
    for (int i = 1; i < prefix.size(); i++)
    {
        prefix[i] = prefix[i - 1] + cakes[i];
    }
    vector<int> k0(prefix.size(), 0);
    vector<int> k1(prefix.size(), 0);
    if (prefix[0] == k)
    {
        k0[0]++;
    }
    for (int i = 1; i < prefix.size(); i++)
    {
        if (prefix[i] == k)
        {
            k0[i] = k0[i - 1] + 1;
        }
        else
        {
            k0[i] = k0[i - 1];
        }
    }
    if (prefix[0] == k + 1)
    {
        k1[0]++;
    }
    for (int i = 1; i < prefix.size(); i++)
    {
        if (prefix[i] == k + 1)
        {
            k1[i] = k1[i - 1] + 1;
        }
        else
        {
            k1[i] = k1[i - 1];
        }
    }

    int ans = INT_MIN;
    int total = k0[k0.size() - 1];
    for (vector<int> q : queries)
    {
        int si = q[0];
        int ei = q[1];

        int loss = k0[ei] - k0[si];
        int gain = k1[ei] - k1[si];
        ans = max(ans, total - loss + gain);
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        int size = 100000;
        cin >> n >> k;
        vector<vector<int>> queries;
        queries.resize(n);
        for (int i = 0; i < n; i++)
        {
            int l, r;
            cin >> l >> r;
            vector<int> query;
            query.push_back(l);
            query.push_back(r);
            queries[i] = query;
        }
        cout << maxrangequeries(size, queries, k) << endl;
    }
}