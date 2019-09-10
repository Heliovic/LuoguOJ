#include <cstdio>
#include <algorithm>
#include <cmath>

#define MAX_LEN 512

using namespace std;

struct bign
{
    int len;
    int digits[MAX_LEN];
    bign() {len = 0; fill_n(digits, MAX_LEN, 0);}

    void print()
    {
        int t = 0;
        for (int i = 499; i >= 0; i--)
        {
            printf("%d", digits[i]);
            t++;
            if (t == 50)
            {
                printf("\n");
                t = 0;
            }
        }
    }
};

bign add(const bign& lhs, const bign& rhs)
{
    bign res;
    int carry = 0;

    for (int i = 0; i < lhs.len || i < rhs.len; i++)
    {
        if (i >= MAX_LEN)
            break;
        int t = lhs.digits[i] + rhs.digits[i] + carry;
        res.digits[res.len++] = t % 10;
        carry = t / 10;
    }

    if (carry && res.len < MAX_LEN)
        res.digits[res.len++] = carry;

    return res;
}

bign mul(const bign& lhs, const bign& rhs)
{
    bign res;

    int offset = 0;

    for (int i = 0; i < lhs.len; i++)
    {
        bign tmp;
        tmp.len = offset;
        int carry = 0;
        for (int j = 0; j < rhs.len; j++)
        {
            int t = rhs.digits[j] * lhs.digits[i] + carry;
            tmp.digits[j + offset] = t % 10;
            tmp.len++;

            if (tmp.len >= MAX_LEN)
                break;

            carry = t / 10;
        }

        if (carry && tmp.len < MAX_LEN)
            tmp.digits[tmp.len++] = carry;

        res = add(res, tmp);
        offset++;
    }

    return res;
}

bign big_pow(const bign& b, int k)
{
    if (k == 0)
    {
        bign r;
        r.digits[r.len++] = 1;
        return r;
    }
    if (k == 1)
        return b;

    bign res = big_pow(b, k / 2);
    res = mul(res, res);

    if (k % 2 == 1)
        res = mul(res, b);

    return res;
}

void sub(bign& b)
{
    int borrow = 1;

    for (int i = 0; i < b.len; i++)
    {
        int t = b.digits[i] - borrow;
        if (t < 0)
        {
            borrow = 1;
            t += 10;
        }
        else
            borrow = 0;
        b.digits[i] = t;
    }

    while (b.len >= 1 && b.digits[b.len - 1] == 0)
        b.len--;
}

int main()
{
    int k;
    scanf("%d", &k);

    bign b;
    b.digits[b.len++] = 2;

    b = big_pow(b, k);

    sub(b);

    printf("%d\n", (int) ceil(k * log10(2)));

    b.print();

    /*bign b;
    b.digits[b.len++] = 1;
    b.digits[b.len++] = 2;
    b.digits[b.len++] = 3;

    b = mul(b, b);
    b.print();*/


    return 0;
}
