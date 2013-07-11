#include <stdio.h>
#include <utility>
#include <queue>
using namespace std;

const int MAX_N = 10000;
const int MAX_M = 10000;
const int INF = 1000000;

typedef std::pair<int, int> P;

int n = 10; // fieldの行
int m = 10; // fieldの列

// S: スタート
// G: ゴール
// .: 通路
// #: 壁
char maze[MAX_N][MAX_N + 1] = {
    {"#S######.#"},
    {"......#..#"},
    {".#.##.##.#"},
    {".#........"},
    {"##.##.####"},
    {"....#....#"},
    {".#######.#"},
    {"....#....."},
    {".####.###."},
    {"....#...G#"},
};

int sx, sy;
int gx, gy;

// スタートからの最短距離
int shortest_dis[MAX_N][MAX_M];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int num_elem;

int bfs()
{
    std::queue<P> que;

    // 最短距離の配列を初期化
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            shortest_dis[i][j] = INF;
            if (maze[i][j] == 'S') {
                printf("S: x=%d, y=%d\n", i, j);
                sx = i;
                sy = j;
            }
            if (maze[i][j] == 'G') {
                printf("G: x=%d, y=%d\n", i, j);
                gx = i;
                gy = j;
            }

        }
    }

    que.push(P(sx, sy));
    shortest_dis[sx][sy] = 0;

    num_elem = que.size();
    while (num_elem) {
        // キューから要素を取り出す
        P p = que.front();
        que.pop();

        if (p.first == gx && p.second == gy) {
            break;
        }

        // 4方向へ移動して壁でなければキューへ要素を追加
        // して、その地点への最短距離を保存
        for (int i = 0; i < 4; i++) {
            int next_x = p.first + dx[i];
            int next_y = p.second + dy[i];

            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m 
                    && maze[next_x][next_y] != '#' && shortest_dis[next_x][next_y] == INF) {
                que.push(P(next_x, next_y));
                shortest_dis[next_x][next_y] = shortest_dis[p.first][p.second] + 1;
            }
        }
        num_elem = que.size();
    }
    return shortest_dis[gx][gy];
}

int main()
{
    int shortest2g = bfs();
    printf("%d\n", shortest2g);
}
