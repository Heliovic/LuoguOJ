#include <cstdio>

using namespace std;

int N;

int main()
{
    scanf("%d", &N);

    int low = 0, high = 4000;

    int t = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if ((mid + mid * mid) / 2 > N)
        {
            high = mid - 1;
        }
        else if ((mid + mid * mid) / 2 < N)
        {
            low = mid + 1;
            t = mid;
        }
        else
        {
            if (mid % 2 == 1)
                printf("1/%d", mid);
            else
                printf("%d/1", mid);
            return 0;
        }
    }

    //printf("%d\n", t);

    int k = N - (t + t * t) / 2;

    if (t % 2 == 1)
        printf("%d/%d", k, t + 2 - k);
    else
        printf("%d/%d", t + 2 - k, k);

    return 0;
}
