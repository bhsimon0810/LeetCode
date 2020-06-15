/*
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, size = nums.size();
        for (int &num : nums) sum += num;
        if (sum % 2) return false;
        sum /= 2;
        vector<vector<bool>> dp(size + 1, vector<bool> (sum + 1, false));
        for (int i = 0; i <= size; ++i) dp[i][0] = true;
        for (int i = 1; i <= size; ++i) {
            for (int j = 1; j <= sum; ++j) {
                if (j - nums[i - 1] < 0)
                    dp[i][j] = dp[i - 1][j];
                else 
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
        return dp[size][sum];
    }
};
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, size = nums.size();
        for (int &num : nums) sum += num;
        if (sum % 2) return false;
        sum /= 2;
        // 状态压缩
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int i = 1; i <= size; ++i)
            for (int j = sum; j >= 0; --j) {
                if (j - nums[i - 1] >= 0)
                    dp[j] = dp[j] || dp[j - nums[i - 1]];
            }
        return dp[sum];
    }
};
