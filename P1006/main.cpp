#include <cstdio>
#include <algorithm>

#define MAX_N 64

using namespace std;

int dp[MAX_N][MAX_N][MAX_N];
int mat[MAX_N][MAX_N];

int M, N;

int main()
{
    fill_n(&dp[0][0][0], MAX_N * MAX_N * MAX_N, 0);
    scanf("%d %d", &M, &N);

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            scanf("%d", &mat[i][j]);

    for (int step = 1; step <= M + N; step++)
    {
        for (int s = 1; s <= min(step + 1, M); s++)
        {
            for (int u = 1; u <= min(step + 1, M); u++)
            {

                int t = step - s + 2;
                int v = step - u + 2;
                int maxx = max(dp[s - 1][u][step - 1], max(dp[s][u - 1][step - 1], max(dp[s][u][step - 1], dp[s - 1][u - 1][step - 1])));
                if (s == u)
                    dp[s][u][step] = maxx + mat[s][t];
                else
                    dp[s][u][step] = maxx + mat[s][t] + mat[u][v];
            }
        }
    }

    printf("%d", dp[M][M][M + N - 2]);

    return 0;
}
