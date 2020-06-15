class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return size;
        // 初始化为全 1 序列
        vector<int> dp(size, 1);
        for (int i = size - 2; i >= 0; --i) {
            for (int j = i + 1; j < size; ++j) {
                if (nums[j] > nums[i]) 
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        int length = 0;
        for (int &l : dp)
            length = max(length, l);
        return length;
    }
};
