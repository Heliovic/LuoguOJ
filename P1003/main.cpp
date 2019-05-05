#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 10240

using namespace std;

struct point
{
    int x, y;
};

struct mp
{
    point p1, p2;
};

vector<mp> mps;
int x, y, n;

int main()
{
    scanf("%d", &n);

    while (n--)
    {
        mp m;
        scanf("%d %d %d %d", &m.p1.x, &m.p1.y, &m.p2.x, &m.p2.y);
        m.p2.x += m.p1.x;
        m.p2.y += m.p1.y;
        mps.push_back(m);
    }

    scanf("%d %d", &x, &y);
    for (int i = mps.size(); i >= 0; i--)
    {
        mp& m = mps[i];
        if (x >= m.p1.x && x <= m.p2.x && y >= m.p1.y && y <= m.p2.y)
        {
            printf("%d", i + 1);
            return 0;
        }
    }

    printf("-1");

    return 0;
}
