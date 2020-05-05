#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll kadane(vector<ll> v)
{
    if (v.size() == 0)
        return 0;
    ll cmax = v[0];
    ll omax = v[0];
    for (ll i = 1; i < v.size(); i++)
    {
        cmax = max(v[i], cmax + v[i]);
        omax = max(cmax, omax);
    }

    return omax;
}
ll kcon(vector<ll> v, int k)
{
    if (k <= 1)
    {
        return kadane(v);
    }
    ll sum = 0;
    for (ll e : v)
    {
        sum += e;
    }
    v.insert(v.end(), v.begin(), v.end());
    ll ans = kadane(v);
    if (sum > 0)
        return ans + (sum * (k - 2));
    else
        return ans;
}

int main()
{

    ll t;
    cin >> t;
    while (t-- > 0)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n, 0);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        cout << kcon(v, k) << endl;
    }

    return 0;
}