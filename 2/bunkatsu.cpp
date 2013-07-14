#include <stdio.h>
const int MAX_N = 1000;
const int MAX_M = 1000;

int n = 4;
int m = 3;
int M = 1000;

int dp[MAX_N + 1][MAX_M + 1];

// nのm分割 a_i: \sum_{i=1}^m a_i = n
// nの(n - m)分割 {a_i - 1}: \sum_{i=1}^m (a_i - 1) = n - m
// a_i = 0となるiが存在するとき、nの(m - 1)分割: \sum_{i=1}^{(m-1)} a_i

int main()
{
    dp[0][0] = 1;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j - i >= 0) {
                // 分割数がアイテムの数より小さい場合
                dp[i][j] = (dp[i - 1][j] + dp[i][j - i]) % M;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    printf("%d\n", dp[m][n]);
}
