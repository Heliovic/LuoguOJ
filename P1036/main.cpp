#include <cstdio>
#include <cmath>

#define MAX_N 32

using namespace std;

int N, K;
int nums[MAX_N];
int ans = 0;

bool is_prime(int p)
{
    if (p < 2)
        return false;

    int sqrtp = sqrt(p);

    for (int i = 2; i <= sqrtp; i++)
        if (p % i == 0)
            return false;
    return true;
}

void dfs(int sum, int n, int pos)
{
    if (n == K)
    {
        if (is_prime(sum))
            ans++;
        return;
    }

    for (int i = pos; i <= N; i++)
        dfs(sum + nums[i], n + 1, i + 1);
}

int main()
{
    scanf("%d %d", &N, &K);

    for (int i = 1; i <= N; i++)
        scanf("%d", nums + i);

    dfs(0, 0, 1);

    printf("%d", ans);

    return 0;
}
