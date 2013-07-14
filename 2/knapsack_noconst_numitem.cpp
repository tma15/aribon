#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

const int MAX_N = 1000;
const int MAX_W = 1000;

int n = 3;
int w[MAX_N] = {3, 4, 2};
int v[MAX_N] = {4, 5, 3};
int W = 7;

int dp[MAX_N + 1][MAX_W + 1];

int main()
{
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i]) {
                dp[i + 1][j] = dp[i][j];
            } else {
                // i番目までの品物から重さの総和がj以下
                // となるように選んだときの価値の総和の最大値
                //
                // i番目の品物を使うとき、使わないとき
                // で重さの総和が大きくなる方を使う
                dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }
    printf("%d\n", dp[n][W]);
}
