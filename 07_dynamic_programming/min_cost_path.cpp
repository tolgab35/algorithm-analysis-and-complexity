#include <iostream>
#include <climits>
using namespace std;

const int N = 3;
int M[N][N] = {
    {1, 5, 1},
    {2, 4, 2},
    {1, 3, 6}
};

int dp[N][N];

int minCost(int i, int j) {
    if (i == N - 1 && j == N - 1)
        return M[i][j];

    if (i >= N || j >= N)
        return INT_MAX;

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = minCost(i + 1, j);
    int right = minCost(i, j + 1);

    dp[i][j] = M[i][j] + min(down, right);
    return dp[i][j];
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = -1;

    cout << "Minimum maliyet: " << minCost(0, 0) << endl;
    return 0;
}
