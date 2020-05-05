int maxArea(vector<int> &height)
{
    if (height.size() == 0)
    {
        return 0;
    }
    int si = 0;
    int ei = height.size() - 1;
    int ans = INT_MIN;
    while (si < ei)
    {
        int area = (ei - si) + min(height[si], height[ei]);
        ans = max(ans, area);
        if (height[si] <= height[ei])
        {
            si++;
        }
        else
            ei--;
    }
    return ans;
}