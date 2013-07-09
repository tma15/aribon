#include <algorithm>

const int MAX_N=10000;

//int n = 3;
//int m = 10;

int n = 3;
int m = 9;

int k[MAX_N] = {1, 3, 5};

//二つの数の組み合わせ
int kk[MAX_N * MAX_N];


bool binary_search(int x)
{
    // xの存在する範囲はkk[left], ..., kk[right + 1]
    int left = 0;
    int right = n * n;

    // 配列の長さが0になるまで繰り返す
    while (right - left >= 1) {
        int center = (left + right) / 2;
        if (kk[center] == x) {
            return true;
        } else if (kk[center] < x) {
            // xはcenterよりも右に存在するのでcenter + 1を左端にする
            left = center + 1;
        } else {
            // xはcenterよりも左に存在するのでcenterを右端にする
            right = center;
        }
    }
    return false;
}

void solve()
{
    // k[c], k[d]のありうる組み合わせを列挙して格納
    for (int c = 0; c < n; c++) {
        for (int d = 0; d < n; d++) {
            kk[c * n + d] = k[c] + k[d];
        }
    }
    // 指定した範囲の要素を並び替える
    std::sort(kk, kk + n*n);

    bool has_answer = false;

    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            if (binary_search(m - k[a] - k[b])) {
                has_answer = true;
            }
        }
    }
    if (has_answer) puts("yes");
    else puts("no");
}

int main()
{
    solve();
}
