class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        if (nums.size() == 0)
            return {};
        int size = nums.size();
        vector<int> prefix(size, 1);
        prefix[0] = nums[0];
        for (int i = 1; i < size; i++)
        {
            prefix[i] = prefix[i - 1] * nums[i];
        }
        int suffix = 1;
        for (int i = size - 1; i >= 0; i--)
        {
            if (i > 0)
                prefix[i] = prefix[i - 1] * suffix;
            else
                prefix[i] = 1 * suffix;
            suffix *= nums[i];
        }
        return prefix;
    }
};