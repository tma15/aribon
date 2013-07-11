#include <stdio.h>

const int MAX_N = 100000;

int n = 4; // 整数の数
int a[MAX_N] = {1, 2, 4, 7}; // すべての整数
int k = 13; // すべての整数から作って欲しい数

bool dfs(int i, int sum)
{
    // n個の整数を使ったときのsumがkになっているか
    if (i == n)
    {
        return sum == k;
    }

    // a[i]を使わなかった時にsum == kとなっているか
    if (dfs(i + 1, sum))
    {
        return true;
    }

    // a[i]を使った時にsum == kとなっているか
    if (dfs(i + 1, sum + a[i]))
    {
        return true;
    }

    // a[i]を使う、使わないに関わらずsum == kとはならない
    return false;
}

void solve()
{
    if (dfs(0, 0))
    {
        printf("Yes\n");
    } else
    {
        printf("No\n");
    }
}

int main()
{
    solve();
}
