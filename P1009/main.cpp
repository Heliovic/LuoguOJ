#include <cstdio>
#include <algorithm>

#define MAX_LEN 128

using namespace std;

struct bign
{
    int nums[MAX_LEN];
    int len;
    bign() {len = 1; fill_n(nums, MAX_LEN, 0);}
};

int N;

bign mul(bign& n1, int m)
{
    bign res = n1;

    int carry = 0;

    for (int i = 0; i < n1.len; i++)
    {
        int t = n1.nums[i] * m + carry;
        res.nums[i] = t % 10;
        carry = t / 10;
    }

    while (carry)
    {
        res.nums[res.len++] = carry % 10;
        carry /= 10;
    }

    return res;
}

bign add(bign n1, bign n2)
{
    if (n2.len > n1.len)
        swap(n1, n2);

    bign res;
    res.len = n1.len;
    int carry = 0;

    int len = n2.len;

    for (int i = 0; i < len; i++)
    {
        int t = n1.nums[i] + n2.nums[i] + carry;
        res.nums[i] = t % 10;
        carry = t / 10;
    }

    for (int i = len; i < n1.len; i++)
    {
        int t = n1.nums[i] + carry;
        res.nums[i] = t % 10;
        carry = t / 10;
    }

    while (carry)
    {
        int t = n1.nums[res.len] + carry;
        res.nums[res.len++] = t % 10;
        carry = t / 10;
    }

    return res;
}

int main()
{
    scanf("%d", &N);

    bign sum, temp;

    temp.nums[0] = 1;

    for (int i = 1; i <= N; i++)
    {
        temp = mul(temp, i);
        /*for (int i = temp.len - 1; i >= 0; i--)
            printf("%d", temp.nums[i]);
        printf("\n");*/
        sum = add(sum, temp);
        /*for (int i = sum.len - 1; i >= 0; i--)
            printf("%d", sum.nums[i]);
        printf("\n");*/
    }

    for (int i = sum.len - 1; i >= 0; i--)
        printf("%d", sum.nums[i]);

    return 0;
}
