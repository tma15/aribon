#include <stdio.h>

const int MAX_N = 10000;

int n = 10; // fieldの行
int m = 12; // fieldの列

char field[MAX_N][MAX_N + 1] = {
    {"W........WW."},
    {".WWW.....WWW"},
    {"....WW...WW."},
    {".........WW."},
    {".........W.."},
    {"..W......W.."},
    {".W.W.....WW."},
    {"W.W.W.....W."},
    {".W.W......W."},
    {"..W.......W."},
};

void dfs(int x, int y)
{
    // 水たまりの広がりを深さ優先探索してWを.に置き換える
    
    // 今いるところを.にする
    field[x][y] = '.';

    // 周囲8マスを移動
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int next_x = x + dx;
            int next_y = y + dy;

            // next_x, next_yが庭の範囲内でかつnext_x, next_yが水たまりかどうか
            if (0 <= next_x && next_x < n && next_y >= 0 && next_y < m && field[next_x][next_y] == 'W') {
                dfs(next_x, next_y);
            }
        }
    }
}

void solve()
{
    int cnt_lake = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == 'W') {
                // Wを.で置き換える
                dfs(i, j);
                cnt_lake++;
            }
        }
    }
    printf("%d\n", cnt_lake);
}

int main()
{
    solve();
}
