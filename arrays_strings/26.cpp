int removeDuplicates(vector<int> &nums)
{
    int i = 0;
    int j = 1;
    int l = 1;

    while (j < nums.size())
    {
        if (nums[i] == nums[j])
        {
            j++;
        }
        else
        {
            nums[l] = nums[j];
            l++;
            i++;
        }
    }
    return i + 1;
}