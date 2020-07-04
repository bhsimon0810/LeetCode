class Solution {
public:
    bool isPalindrome(int x) {
        // 首先判断负数和个位数为零的正整数
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int reverted = 0;
        // 直到 x 小于或等于 reverted 可以停止，然后判断数值大小
        while (x > reverted) {
            reverted = (reverted * 10) + (x % 10);
            x /= 10;
        }
        // 偶数位 || 奇数位
        return x == reverted || x == reverted / 10;
    }
};
