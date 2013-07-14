#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX_N = 1000;
const int MAX_W = 1000;

int n = 4;
int w[MAX_N] = {2, 1, 3, 2};
int v[MAX_N] = {3, 2, 4, 2};
int W = 5;

int dp[MAX_N + 1][MAX_W + 1];

int rec(int i, int j)
{
    if (dp[i][j] >= 0) {
        return dp[i][j];
    }

    int total_w;
    if (i == n) {
        total_w = 0;
    } else if (j < w[i]) {
        total_w = rec(i + 1, j);
    } else {
        total_w = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
    }
    return dp[i][j] = total_w;
}

int dp_rev()
{
    // dpはi番目以降の品物から重さの総和がj以下となるように選んだときの
    // 価値の総和の最大値
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i]) { // w[i]がjを超えるとナップサックに入れられない
                dp[i][j] = dp[i + 1][j];
            } else { // i番目の品物を入れた場合、入れない場合で価値が大きくなるほうを選ぶ
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }
    printf("%d\n", dp[0][W]);
}

int dp_for()
{
    // dpはi番目までの品物から重さの総和がj以下となるように選んだときの
    // 価値の総和の最大値
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i]) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
            }
        }
    }
    printf("%d\n", dp[n][W]);
}

int dp_state()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < W; j++) {
            // i+1番目までの品物から重さの総和がj以下となるように選ぶ状態
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

            // i+1番目の品物から重さの総和がj+w[i]以下となるように選ぶ状態
            if (j + w[i] <= W) {
                dp[i + 1][j + w[i]] = max(dp[i + 1][j + w[i]], dp[i][j] + v[i]);
            }
        }
    }
    printf("%d\n", dp[n][W]);
}

int main()
{
    // まだ調べていないことを表す-1で初期化
    memset(dp, -1, sizeof(dp));
    printf("%d\n", rec(0, W));

    // 直前の値を利用するので0で初期化
    memset(dp, 0, sizeof(dp));
    dp_rev();

    memset(dp, 0, sizeof(dp));
    dp_for();

    memset(dp, 0, sizeof(dp));
    dp_state();
}
