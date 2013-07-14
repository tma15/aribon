#include <string.h>
#include <stdio.h>>

const int MAX_K = 1000;

int n = 3;
int a[MAX_K] = {3, 5, 8};
int m[MAX_K] = {3, 2, 2};
int K = 17;

int dp[MAX_K + 1]; // jを作る際にあまる最大の個数

int main()
{
    memset(dp, -1, sizeof(dp));

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= K; j++) {
            if (dp[j] >= 0) {
                // a[i]を使わない
                dp[j] = m[i];
            } else if (j < a[i] || dp[j - a[i]] <= 0) {
                // a[i]を使うとjを超えてしまう
                dp[j] = -1;
            } else {
                // a[i]を一つ使ってjを作る
                dp[j] = dp[j - a[i]] - 1;
            }
        }
    }
    if (dp[K] >= 0) {
        printf("Yes\n");
    }
}
