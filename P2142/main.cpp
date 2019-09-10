#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAX_LEN 10240

using namespace std;

struct bign
{
    int digits[MAX_LEN];
    int len;
    bign() {len = 0; fill_n(digits, MAX_LEN, 0);}
    void scan()
    {
        char buf[MAX_LEN];
        scanf("%s", buf);
        char ch;
        int sl = strlen(buf);
        for (int i = 0; i < sl; i++)
            digits[len++] = buf[i] - '0';
        reverse(digits, digits + len);
    }
};

bool gte(const bign& b1, const bign& b2)
{
    if (b1.len != b2.len)
        return b1.len > b2.len;
    for (int i = b1.len - 1; i >= 0; i--)
        if (b1.digits[i] < b2.digits[i])
            return false;
    return true;
}

bign sub(const bign& b1, const bign& b2)
{
    int borrow = 0;

    bign res;

    for (int i = 0; i < b2.len; i++)
    {
        int t = b1.digits[i] - b2.digits[i] - borrow;
        if (t < 0)
        {
            borrow = 1;
            t += 10;
        }
        else
            borrow = 0;
        res.digits[i] = t;
    }

    for (int i = b2.len; i < b1.len; i++)
    {
        int t = b1.digits[i] - borrow;
        if (t < 0)
        {
            borrow = 1;
            t += 10;
        }
        else
            borrow = 0;
        res.digits[i] = t;
    }

    res.len = b1.len;

    while (res.len > 1 && res.digits[res.len - 1] == 0)
        res.len--;

    return res;
}

int main()
{
    bign b1, b2;
    b1.scan();
    b2.scan();

    if (!gte(b1, b2))
    {
        printf("-");
        swap(b1, b2);
    }

    bign res = sub(b1, b2);

    for (int i = res.len - 1; i >= 0; i--)
        printf("%d", res.digits[i]);

    //printf("\n");

    return 0;
}
