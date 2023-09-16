// https://leetcode.com/problems/house-robber-ii/
// dynamic problem
class Solution
{
public:
    int max_rob(vector<int>& money, int start, int end)
    {
        if (start == end)
            return money[start];

        int prev1 = 0, prev2 = 0;

        for (int i = start; i <= end; i++)
        {
            int current = max(prev1 + money[i], prev2);
            prev1 = prev2;
            prev2 = current;
        }

        return prev2;
    }
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        int m1 = max_rob(nums, 0, n - 2);
        int m2 = max_rob(nums, 1, n - 1);

        return max(m1, m2);
    }
};