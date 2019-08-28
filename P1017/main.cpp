#include <cstdio>
#include <vector>

using namespace std;

int N, R;

int main()
{
    scanf("%d %d", &N, &R);

    printf("%d=", N);

    vector<char> digit;

    do
    {
        int t = N % R;
        if (t < 0)
        {
            t -= R;
            N += R;
        }
        N /= R;
        digit.push_back(t >= 10 ? t + 'A' - 10 : t + '0');
    } while (N);

    for (int i = digit.size() - 1; i >= 0; i--)
        putchar(digit[i]);

    printf("(base%d)", R);

    return 0;
}
