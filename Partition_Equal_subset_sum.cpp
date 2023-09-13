// https://leetcode.com/problems/partition-equal-subset-sum/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            total_sum += nums[i];
        }

        if (total_sum % 2 != 0) {
            return false;
        } else {
            int target = total_sum / 2;
            int n = nums.size() - 1;
            vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
            int subset = subset_sum(nums, dp, n, target);
            return subset;
        }
    }

    int subset_sum(vector<int>& nums, vector<vector<int>>& dp, int n, int target) {
        // 1. Base case
        if (n == 0) {
            if (target == 0) {
                return 1;
            }
            return 0;
        }

        // 2. If result is already calculated
        if (dp[n][target] != -1) {
            return dp[n][target];
        }

        // 3. Calculate result from smaller problems
        int ans1 = subset_sum(nums, dp, n - 1, target);
        if (target < nums[n]) {
            dp[n][target] = ans1;
            return ans1;
        }
        int ans2 = subset_sum(nums, dp, n - 1, target - nums[n]);
        int ans = ans1 || ans2;
        dp[n][target] = ans;
        return ans;
    }
};