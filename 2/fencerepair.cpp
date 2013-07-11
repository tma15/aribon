#include <algorithm>
#include <stdio.h>
using namespace std;

typedef long long ll;

const int MAX_N = 10000;

int n = 3; // 切り出したい板の数
int l[MAX_N] = {8, 5, 8}; // 切り出したい板の長さ

int main()
{
    ll cost = 0;

    // 板の数が1になるまで繰り返す
    while (n > 1) {
        int mii1 = 0; // 一番短い板のid
        int mii2 = 1; // 二番目に短い板のid

        if (l[mii1] > l[mii2]) {
            swap(mii1, mii2);
        }

        for (int i = 2; i < n; i++) {
            if (l[i] < l[mii1]) {
                mii2 = mii1;
                mii1 = i;
            } else if (l[i] < l[mii2]) {
                mii2 = i;
            }
        }

        // 板をくっつける
        int t = l[mii1] + l[mii2];
        cost += t;

        if (mii1 == n - 1)
        {
            swap(mii1, mii2);
        }
        l[mii1] = t; // mii1にくっつけた板の長さを入れる
        l[mii2] = l[n - 1]; // mii2はあとで使わない
//        printf("n=%d\n", n);
//        for (int i = 0; i < n; i++) {
//            printf("l[%d] = %d\n", i, l[i]);
//        }
        n--;
    }
    printf("%lld\n", cost);
}
