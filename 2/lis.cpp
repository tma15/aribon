#include <algorithm>
#include <string.h>
using namespace std;

const int MAX_N = 1000;

int n = 5;
int a[MAX_N] = {4, 2, 3, 1, 5};

// dp[i]: 最後がa_iであるような最長の増加部分列の長さ
int dp[MAX_N + 1]; 

int main()
{
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        dp[i + 1] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                // dp[i + 1]: a_iのみからなる列
                dp[i + 1] = max(dp[i + 1], dp[j] + 1);
            }
        }
    }
    printf("%d\n", dp[n]);
}
