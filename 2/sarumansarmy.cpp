#include <algorithm>
#include <stdio.h>
const int MAX_N = 10000;

int n = 6; // 点の数
int r = 10; // チェックされた点が持つ線の長さ
int x[MAX_N] = {1, 7, 15, 20, 30, 50}; // 点の位置

int main()
{
    std::sort(x, x + n);
    
    int i = 0;    
    int num_checked_point = 0;
    while (i < n) {
        // カバーされていない一番左の点
        // xのうちで最も左の点が選択されることはない
        int mostleft = x[i++];

        // 一番左の点からrを超えるまで進む
        while (i < n && x[i] <= mostleft + r) {
            i++;
        }

        int new_checked_point = x[i - 1];
        // 新しく選択された点からrを超えるまで進む
        while (i < n && x[i] <= new_checked_point + r) {
            i++;
        }
        num_checked_point++;
    }
    printf("%d\n", num_checked_point);
}
