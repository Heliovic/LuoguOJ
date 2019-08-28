#include <cstdio>
#include <vector>
#include <climits>

#define MAX_N 16

using namespace std;

double D1, C, D2, P;
int N;
double ds[MAX_N];
double ps[MAX_N];

int main()
{
    scanf("%lf %lf %lf %lf %d", &D1, &C, &D2, &P, &N);

    for (int i = 1; i <= N; i++)
        scanf("%lf %lf", &ds[i], &ps[i]);

    ds[0] = 0;
    ps[0] = P;
    ds[N + 1] = D1;
    ps[N + 1] = INT_MAX;

    int ptr = 0;
    double price = 0;
    double cur_fuel = 0;

    while (ptr < N + 1)
    {
        //printf("%d\n", ptr);
        double dis_to_go = C * D2;

        double min_price = ps[ptr];
        int min_pos = ptr;
        int i;
        for (i = ptr; i <= N + 1 && dis_to_go >= ds[i] - ds[ptr]; i++)
        {
            if (min_price > ps[i])
            {
                min_pos = i;
                min_price = ps[i];
            }
        }

        if (i == ptr)
        {
            printf("No Solution");
            return 0;
        }

        //printf("%d\n", i);

        if (min_pos != ptr)
        {
            double fuel = (ds[min_pos] - ds[ptr]) / D2;
            if (fuel > cur_fuel)
            {
                price += (fuel - cur_fuel) * ps[ptr];
                cur_fuel = fuel;
            }

            cur_fuel -= fuel;
            ptr = min_pos;
        }
        else
        {
            double delta;
            if (N + 1 == i - 1)
                delta = (D1 - ds[ptr]) / D2 - cur_fuel;
            else
                delta = C - cur_fuel;
            price += delta * ps[ptr];

            double dis = ds[i - 1] - ds[ptr];
            double fuel_need = dis / D2;
            cur_fuel = C - fuel_need;
            if (ptr == i - 1)
            {
                printf("No Solution");
                return 0;
            }
            ptr = i - 1;
        }
    }

    printf("%.2f", price);

    return 0;
}
