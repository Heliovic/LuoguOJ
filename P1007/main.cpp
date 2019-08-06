#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> ss;
int N, L;

int main()
{
    scanf("%d %d", &L, &N);

    if (N == 0)
    {
        printf("0 0");
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        int t;
        scanf("%d", &t);
        ss.push_back(t);
    }

    int ans1 = INT_MIN, ans2 = INT_MIN;

    for (int i = 0; i < N; i++)
    {
        int maxx = max(L + 1 - ss[i], ss[i]);
        int minn = min(L + 1 - ss[i], ss[i]);
        ans1 = max(ans1, minn);
        ans2 = max(ans2, maxx);
    }

    printf("%d %d", ans1, ans2);

    return 0;
}
