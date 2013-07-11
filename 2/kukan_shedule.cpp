#include <stdio.h>
#include <utility>
#include <algorithm>

using namespace std;

const int MAX_N = 10000;

int n = 5; // 仕事の数
int s[MAX_N] = {1, 2, 4, 6, 8}; // 仕事の開始時間
int t[MAX_N] = {3, 5, 7, 9, 10}; // 仕事の終了時間

std::pair<int, int> jobs[MAX_N];

int main()
{
    for (int i = 0; i < n; i++) {
        jobs[i].first = t[i];
        jobs[i].second = s[i];
    }
    // 終了時間の早い順にソート
    std::sort(jobs, jobs + n);

    int num_jobs = 0;
    int ends_last_job = 0;
    for (int i = 0; i < n; i++) {
        // 次に選べる仕事のうち、最も早く終わるものを選ぶ
        // 仕事の候補は最後に選んだ仕事の終了時間と
        // 開始時間がかぶらないもの
        if (ends_last_job < jobs[i].second) {
            num_jobs++;
            ends_last_job = jobs[i].first;
        }
    }
    printf("%d\n", num_jobs);
}
