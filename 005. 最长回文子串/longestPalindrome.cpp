/* 动态规划
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        string ans;
        vector<vector<bool>> dp(size, vector<bool>(size, false));
        for (int l = 0; l < size; ++l)
            for (int i = 0; i + l < size; ++i) {
                int j = i + l;
                if (l == 0)
                    dp[i][j] = true;
                else if (l == 1)
                    dp[i][j] = (s[i] == s[j]);
                else 
                    dp[i][j] = (dp[i + 1][j - 1] && (s[i] == s[j]));
                // 如果此时 dp[i][j] 是回文子串，判断是否是当前最长
                if (dp[i][j] && l + 1 > ans.size())
                    ans = s.substr(i, l + 1);
            }
        return ans;
    }
};*/

// 中心展开
class Solution {
    int expandFromCenter(string s, int left, int right) {
        // while (left >= 0 && right < s.size() && s[left--] == s[right++]); 错误
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left; ++right;
        }
        return right - left - 1;
    }
public:
    string longestPalindrome(string s) {
        if (s.size() < 1) return "";
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            int len1 = expandFromCenter(s, i, i);
            int len2 = expandFromCenter(s, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start + 1) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
