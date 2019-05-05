#include <cstdio>
#include <set>
#include <algorithm>

#define MAX_N 32

using namespace std;

long long ans[MAX_N][MAX_N];

set<int> horse;
int n, m, hx, hy;

long long result = 0;

void dfs(int x, int y)
{
    if (horse.find(x * MAX_N + y) != horse.end())
        return;
    if (ans[x][y] != -1)
    {
        result += ans[x][y];
        return;
    }
    if (x == n && y == m)
    {
        result++;
        return;
    }
    long long delta = result;
    if (x < n)
        dfs(x + 1, y);
    if (y < m)
        dfs(x, y + 1);
    delta = result - delta;
    ans[x][y] = delta;
}

int main()
{
    fill_n(&ans[0][0], MAX_N * MAX_N, -1);
    scanf("%d %d %d %d", &n, &m, &hx, &hy);
    horse.insert(hx * MAX_N + hy);
    horse.insert((hx + 1) * MAX_N + hy + 2);
    horse.insert((hx + 1) * MAX_N + hy - 2);
    horse.insert((hx + 2) * MAX_N + hy + 1);
    horse.insert((hx + 2) * MAX_N + hy - 1);
    horse.insert((hx - 1) * MAX_N + hy - 2);
    horse.insert((hx - 1) * MAX_N + hy + 2);
    horse.insert((hx - 2) * MAX_N + hy - 1);
    horse.insert((hx - 2) * MAX_N + hy + 1);
    dfs(0, 0);
    printf("%lld", result);
    return 0;
}
