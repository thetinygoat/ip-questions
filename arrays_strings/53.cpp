int maxSubArray(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    int cmax = nums[0];
    int omax = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        cmax = max(nums[i], cmax + nums[i]);
        omax = max(cmax, omax);
    }

    return omax;
}