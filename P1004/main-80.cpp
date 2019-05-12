#include <cstdio>
#include <algorithm>

#define MAX_N 16
#define R true
#define UP false

using namespace std;

int mat[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
bool dir[MAX_N][MAX_N];
int N;

int main()
{
    fill_n(&mat[0][0], MAX_N * MAX_N, 0);
    fill_n(&dp[0][0], MAX_N * MAX_N, 0);
    scanf("%d", &N);

    int s, t, d;
    scanf("%d %d %d", &s, &t, &d);

    while (s != 0 || t != 0 || d != 0)
    {
        mat[t][s] = d;
        scanf("%d %d %d", &s, &t, &d);
    }

    dp[N][N] = mat[N][N];
    mat[N][N] = 0;

    for (int i = N - 1; i >= 1; i--)
    {
        dp[i][N] = mat[i][N] + dp[i + 1][N];
        dir[i][N] = R;
        dp[N][i] = mat[N][i] + dp[N][i + 1];
        dir[N][i] = UP;
    }

    for (int b = 2 * N - 1; b >= 1; b--)
    {
        int y;
        for (int x = N - 1; (y = -x + b) <= N - 1; x--)
        {
            if (x < 1 || y < 1)
                continue;
            if (dp[x + 1][y] > dp[x][y + 1])
            {
                dir[x][y] = R;
                dp[x][y] = dp[x + 1][y] + mat[x][y];
            }
            else
            {
                dir[x][y] = UP;
                dp[x][y] = dp[x][y + 1] + mat[x][y];
            }
        }
    }

    int ans = dp[1][1];

    s = 1, t = 1;

    while (!(s == N && t == N))
    {
        mat[s][t] = 0;
        if (dir[s][t] == R)
            s++;
        else
            t++;
    }

    mat[N][N] = 0;

    // 2 dp

    fill_n(&dp[0][0], MAX_N * MAX_N, 0);

    dp[N][N] = mat[N][N];
    mat[N][N] = 0;

    for (int i = N - 1; i >= 1; i--)
    {
        dp[i][N] = mat[i][N] + dp[i + 1][N];
        dir[i][N] = R;
        dp[N][i] = mat[N][i] + dp[N][i + 1];
        dir[N][i] = UP;
    }

    for (int b = 2 * N - 1; b >= 1; b--)
    {
        int y;
        for (int x = N - 1; (y = -x + b) <= N - 1; x--)
        {
            if (x < 1 || y < 1)
                continue;
            if (dp[x + 1][y] > dp[x][y + 1])
            {
                dir[x][y] = R;
                dp[x][y] = dp[x + 1][y] + mat[x][y];
            }
            else
            {
                dir[x][y] = UP;
                dp[x][y] = dp[x][y + 1] + mat[x][y];
            }
        }
    }

    ans += dp[1][1];

    printf("%d", ans);

    return 0;
}
