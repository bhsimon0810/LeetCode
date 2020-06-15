/*
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        int size = coins.size();
        vector<vector<int>> dp(size + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i <= size; ++i) dp[i][0] = 1;
        for (int i = 1; i <= size; ++i)
            for (int j = 1; j <= amount; ++j) {
                if (j >= coins[i - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                else 
                    dp[i][j] = dp[i - 1][j];
            }
        return dp[size][amount];
    }
};
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        int size = coins.size();
        // 状态压缩
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= size; ++i)
            for (int j = 1; j <= amount; ++j)
                if (j >= coins[i - 1])
                    dp[j] = dp[j] + dp[j - coins[i - 1]];
        return dp[amount];
    }
};
