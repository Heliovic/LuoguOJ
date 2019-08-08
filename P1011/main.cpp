#include <cstdio>
#include <algorithm>

using namespace std;

struct ats
{
    int a, t;
    ats() {a = t = 0;}
};

int A, N, M, X, T;

ats bak[32];
bool bbak[32];

ats f(int n)
{
    ats a;
    if (n == 1 || n == 2)
    {
        a.a = 1;
        return a;
    }
    else if (n == 3)
    {
        a.a = 2;
        return a;
    }

    if (bbak[n])
        return bak[n];

    ats a1 = f(n - 1);
    ats a2 = f(n - 2);

    a.a = a1.a + a2.a;
    a.t = a1.t + a2.t;
    a.a--;
    a.t++;

    bbak[n] = true;
    bak[n] = a;

    return a;
}

int main()
{
    fill_n(bbak, 32, false);

    scanf("%d %d %d %d", &A, &N, &M, &X);

    ats a = f(N - 1);

    T = (M - a.a * A) / a.t;

    a = f(X);

    printf("%d", a.a * A + a.t * T);

    return 0;
}
