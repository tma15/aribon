#include <algorithm>
using namespace std;

const int V[6] = {1, 5, 10, 50, 100, 500}; // コインの金額
int C[6] = {3, 2, 1, 3, 0, 2}; // コインの枚数
int A = 620; // 支払額

int main()
{
    // 使用するコインの枚数
    int amount = 0;

    for (int i = 5; i >= 0; i--) {
        // コインiを使う枚数
        // Aを超えない枚数、もしくは全部使う
        int num_ci = std::min(A / V[i], C[i]);

        A -= num_ci * V[i];
        amount += num_ci;
    }
    printf("%d\n", amount);
}
