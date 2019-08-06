#include <cstdio>
#include <algorithm>

using namespace std;

bool mp[10];

void dfs(int a, int b, int c, int cnt)
{
    //printf("%d %d %d\n", a, b, c);
    if (cnt == 10)
    {
        if (3 * a == c)
            printf("%d %d %d\n", a, b, c);
        return;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (mp[i])
            continue;

        mp[i] = true;

        if (cnt <= 3)
            dfs(a * 10 + i, b, c, cnt + 1);
        else if (cnt <= 6)
        {
            int t = b * 10 + i;
            if (cnt == 6 && 2 * a != t)
            {
                mp[i] = false;
                continue;
            }
            dfs(a, t, c, cnt + 1);
        }
        else
            dfs(a, b, c * 10 + i, cnt + 1);

        mp[i] = false;
    }


}

int main()
{
    fill_n(mp, 10, false);
    dfs(0, 0, 0, 1);
    return 0;
}
