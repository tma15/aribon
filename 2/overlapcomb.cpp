#include <stdio.h>
const int MAX_N = 1000;
const int MAX_M = 1000;

int n = 3;
int m = 3;
int a[MAX_N] = {1, 2, 3};
int M = 1000;

int dp[MAX_N + 1][MAX_M + 1];

int main()
{
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i - 1 - a[i] >= 0) {
                dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]] + M) % M;
            } else {
                dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % M;
            }
        }
    }
    printf("%d\n", dp[n][m]);
}
