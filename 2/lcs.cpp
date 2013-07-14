#include <stdio.h>>
#include <algorithm>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;

char s[MAX_N] = {"abcd"};
char t[MAX_M] = {"becd"};
int n = 4; // sの長さ　
int m = 4; // mの長さ

int dp[MAX_N + 1][MAX_M + 1];

int main()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) {
                // i番目までの部分文字列s_{1..i}と
                // j番目までの部分文字列t_{1..j}に1を足すだけ
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                // s[i]とt[j]は別の文字なのでどちらか
                // 大きい方を選ぶ
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    printf("%d\n", dp[n][m]);
}
