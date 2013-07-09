#include <stdio.h>
const int MAX_N = 100000;
int n = 5;
int a[MAX_N] = {2, 3, 4, 5, 10};

int max(int x, int y)
{
    if(x > y)
    {
        return x;
    } else {
        return y;
    }
}

void solve()
{
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int len = a[i] + a[j] + a[k];
                int ma = max(a[i], max(a[j], a[k]));
                int rest = len - ma;

                // 三角形の必要十分条件
                // 最長の棒の長さ < 他の二本の棒の長さ
                if (ma < rest){
                    ans = max(ans, len);
                }
            }
        }
    }
    printf("ans %d\n", ans);
}

int main()
{
    solve();
}
