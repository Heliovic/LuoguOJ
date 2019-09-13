#include <cstdio>

using namespace std;

int N, K;
int ans = 0;

void dfs(int begin, int sum, int k)
{
    if (sum == N && k == K)
    {
        ans++;
        return;
    }

    if (sum >= N || k == K + 1)
        return;

    if (/*begin * (K - k) + sum > N || */(N - 1) * (K - k) + sum < N)
        return;

    for (int i = begin; i * (K - k) + sum <= N; i++)
        dfs(i, sum + i, k + 1);
}

int main()
{
    scanf("%d %d", &N, &K);

    if (K == 1)
    {
        printf("1");
        return 0;
    }

    dfs(1, 0, 0);

    printf("%d", ans);

    return 0;
}
