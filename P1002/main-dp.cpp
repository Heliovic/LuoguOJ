#include <cstdio>
#include <set>

#define MAX_N 32

using namespace std;

long long dp[MAX_N][MAX_N];

int n, m, hx, hy;
set<int> horse;

int main()
{
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
	
	dp[n][m] = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (horse.find(i * MAX_N + m) != horse.end())
			dp[i][m] = 0;
		else
			dp[i][m] = dp[i + 1][m];
	}
	for (int i = m - 1; i >= 0; i--)
	{
		if (horse.find(n * MAX_N + i) != horse.end())
			dp[n][i] = 0;
		else
			dp[n][i] = dp[n][i + 1];
	}
	for (int b = m + n - 1; ; b--)
	{
		for (int x = b - m + 1; x < n; x++)
		{
			int y = -x + b;
			if (x < 0 || y < 0)
				continue;
			if (horse.find(x * MAX_N + y) != horse.end())
				continue;
			dp[x][y] = dp[x + 1][y] + dp[x][y + 1];
			if (x == 0 && y == 0)
			{
				printf("%lld", dp[0][0]);
				return 0;
			}
		}
	}
}