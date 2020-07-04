/*
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};*/

class Solution {
    struct stone {
        int first, second;
        stone(int first, int second) { this->first = first; this->second = second; }
    };
public:
    bool stoneGame(vector<int>& piles) {
        int size = piles.size();
        vector<vector<stone>> dp(size, vector<stone>(size, stone(0, 0)));
        // 初始化 base case
        for (int i = 0; i < size; ++i) {
            dp[i][i].first = piles[i];
            dp[i][i].second = 0;
        }
        // 状态转移，沿对角线斜向遍历
        // 第一个遍历变量是指第几条对角线，索引从 1 开始（第零条已经被填充）
        for (int l = 1; l < size; ++l)
            for (int i = 0; i < size - l; ++i) {
                int j = l + i;
                // 判断先手是选择左侧还是右侧，注意做出选择后当前先手转移至下一次选择的后手
                int left = piles[i] + dp[i + 1][j].second;
                int right = piles[j] + dp[i][j - 1].second;
                // 做出选择，然后确定当前后手的值
                if (left > right) {
                    dp[i][j].first = left;
                    dp[i][j].second = dp[i + 1][j].first;
                }
                else {
                    dp[i][j].first = right;
                    dp[i][j].second = dp[i][j - 1].first;
                }
            }
        return dp[0][size - 1].first > dp[0][size - 1].second;
    }
};
