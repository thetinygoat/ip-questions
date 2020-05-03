void reverse(int si, int ei, vector<int> &nums)
{
    while (si < ei)
    {
        int temp = nums[si];
        nums[si] = nums[ei];
        nums[ei] = temp;
        si++;
        ei--;
    }
}
void rotate(vector<int> &nums, int k)
{
    int size = nums.size() - 1;
    if (size <= 0)
        return;
    if (k > nums.size())
        k %= nums.size();
    reverse(0, size - k, nums);
    reverse(size - k + 1, size, nums);
    reverse(0, size, nums);
}