/*
class Solution {
    unordered_map<int, int> memo;
    int superEggDropHelper(int K, int N) {
        if (memo.find(N * 100 + K) == memo.end()) {
            if (K == 1) return N;
            if (N == 0) return 0;

            int lo = 1, hi = N;
            while (lo + 1 < hi) {
                int mid = (lo + hi) / 2;
                int t1 = superEggDropHelper(K - 1, mid - 1);
                int t2 = superEggDropHelper(K, N - mid);
                if (t1 < t2)
                    lo = mid;
                else if (t1 > t2)
                    hi = mid;
                else 
                    lo = hi = mid;
            }
            int ans = 1 + min(
                max(superEggDropHelper(K - 1, lo - 1), superEggDropHelper(K, N - lo)),
                max(superEggDropHelper(K - 1, hi - 1), superEggDropHelper(K, N - hi))
            );
            memo[N * 100 + K] = ans;
        }
        return memo[N * 100 + K];
    }
public:
    int superEggDrop(int K, int N) {
        return superEggDropHelper(K, N);
    }
};
*/
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
        int m = 0;
        while (dp[K][m] < N) {
            ++m;
            for (int k = 1; k <= K; ++k) {
                dp[k][m] = dp[k][m - 1] + dp[k - 1][m - 1] + 1;
            }
        }
        return m;
    }
};
