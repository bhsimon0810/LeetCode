class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));
        // 状态初始化
        for (int i = 0; i < size; ++i)
            dp[i][i] = 1;
        // 状态遍历，i > j 的时候值全为零
        for (int i = size - 2; i >= 0; --i)
            for (int j = i + 1; j < size; ++j)
                if (s[i] == s[j])
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else 
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        return dp[0][size - 1];
    }
};
