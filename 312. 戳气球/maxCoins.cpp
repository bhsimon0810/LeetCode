class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
        vector<int> points(size + 2, 1);
        for (int i = 1; i <= size; ++i)
            points[i] = nums[i - 1];
        vector<vector<int>> dp(size + 1, vector<int>(size + 2, 0));
        for (int i = size; i >= 0; --i)
            for (int j = i + 1; j <= size + 1; ++j)
                for (int k = i + 1; k < j; ++k)
                    dp[i][j] = max(
                        dp[i][j],
                        dp[i][k] + dp[k][j] + points[i] * points[j] * points[k]
                    );
        return dp[0][size + 1];

    }
};
