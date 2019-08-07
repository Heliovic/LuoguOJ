#include <cstdio>
#include <vector>

using namespace std;

int N;

int printk(int k)
{
    vector<int> res;

    int p = 0;

    do
    {
        if (k % 2)
            res.push_back(p);
        k /= 2;
        p++;
    } while (k);

    for (int i = res.size() - 1; i >= 0; i--)
    {
        if (res[i] == 1)
            printf("2");
        else
        {
            printf("2(");
            if (res[i] > 2)
                printk(res[i]);
            else
                printf("%d", res[i]);
            printf(")");
        }

        if (i != 0)
            printf("+");
    }
}

int main()
{
    scanf("%d", &N);
    printk(N);
    return 0;
}
