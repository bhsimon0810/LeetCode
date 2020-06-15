class Solution {
public:
    int fib(int N) {
        // 边界判断，默认输入正整数
        if (N < 2) return N;
        int prev = 0, curr = 1, sum = 0;
        for (int i = 2; i <= N; ++i) {
            sum = prev + curr;
            prev = curr;
            curr = sum;
        }
        return curr;
    }
};
