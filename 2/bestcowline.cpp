#include <stdio.h>
const int MAX_N = 100000;

int n = 6; // 文字列の長さ
char s[MAX_N] = {"ACDBCB"}; // 文字列

int main()
{
    // s[a], s[a+1],...,s[b-1], s[b]
    int a = 0;
    int b = n - 1;

    while (a <= b)
    {
        bool use_left = false;
        // aとbが同じ位置になるまで繰り返す
        for (int i = 0; a + i <= b; i++) {
            if (s[a + i] < s[b - i]) {
                use_left = true;
                break;
            } else if (s[a + i] > s[b - i]) {
                use_left = false;
                break;
            }
        }    
        if (use_left) {
            putchar(s[a++]);
        } else {
            putchar(s[b--]);
        }
        putchar('\n');
    }
}
