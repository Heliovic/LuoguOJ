#include <cstdio>
#include <algorithm>

#define MAX_N 16

using namespace std;

int mat[MAX_N][MAX_N];
int dp[MAX_N][MAX_N][MAX_N][MAX_N];
int N;

int main()
{
    fill_n(&mat[0][0], MAX_N * MAX_N, 0);
    fill_n(&dp[0][0][0][0], MAX_N * MAX_N * MAX_N * MAX_N, 0);
    scanf("%d", &N);

    int s, t, d;
    scanf("%d %d %d", &s, &t, &d);

    while (s != 0 || t != 0 || d != 0)
    {
        mat[t][s] = d;
        scanf("%d %d %d", &s, &t, &d);
    }

    for (int s = 1; s <= N; s++)
    {
        for (int t = 1; t <= N; t++)
        {
            for (int u = 1; u <= N; u++)
            {
                for (int v = 1; v <= N; v++)
                {
                    int maxx = max(dp[s - 1][t][u - 1][v], dp[s][t - 1][u - 1][v]);
                    maxx = max(maxx, dp[s - 1][t][u][v - 1]);
                    maxx = max(maxx, dp[s][t - 1][u][v - 1]);
                    if (s == u && t == v)
                        dp[s][t][u][v] = maxx + mat[s][t];
                    else
                        dp[s][t][u][v] = maxx + mat[s][t] + mat[u][v];
                }
            }
        }
    }
    printf("%d", dp[N][N][N][N]);

    return 0;
}
