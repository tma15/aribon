#include <algorithm>
#include <iostream>

const int MAX_N = 10000;
int L = 10; // 棒の長さ
int n = 3; // アリの数
int x[MAX_N] = {2, 6, 7}; // 左端からのアリの位置

void solve()
{
    int minT = 0;
    for (int i = 0; i < n; i++) {
        // 一番遠くのアリが落ちる時間
        minT = std::max(minT, std::min(x[i], L - x[i]));
    }

    int maxT = 0;
    for (int i = 0; i < n; i++) {
        // 一番遠くのアリが落ちる時間
        maxT = std::max(maxT, std::max(x[i], L - x[i]));
    }
    printf("%d %d\n", minT, maxT);
}

int main()
{
    solve();
}
