class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));
        // 初始化边界条件
        for (int i = 0; i <= size1; ++i)
            dp[i][0] = i;
        for (int j = 0; j <= size2; ++j)
            dp[0][j] = j;
        // 根据转移方程求解
        for (int i = 1; i <= size1; ++i)
            for (int j = 1; j <= size2; ++j)
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else 
                    dp[i][j] = minOfThree(
                        // 插入
                        1 + dp[i][j - 1],
                        // 删除
                        1 + dp[i - 1][j],
                        // 替换
                        1 + dp[i - 1][j - 1]
                    );
        return dp[size1][size2];
    }

    int minOfThree(int v1, int v2, int v3) {
        return min(min(v1, v2), v3);
    }
};
