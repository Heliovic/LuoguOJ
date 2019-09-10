#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

#define MAX_LEN 32

using namespace std;

set<int> mapping[10];

int K;
vector<int> num;
bool canbe[10];

struct bign
{
    int len;
    int digits[MAX_LEN];
    bign() {len = 1; fill_n(digits, MAX_LEN, 0);}
};

void dfs(int k)
{
    if (canbe[k])
        return;
    canbe[k] = true;

    for (set<int>::iterator it = mapping[k].begin(); it != mapping[k].end(); it++)
        dfs(*it);
}

void mul(bign& b, int k)
{
    int carry = 0;

    for (int i = 0; i < b.len; i++)
    {
        int t = b.digits[i] * k + carry;
        b.digits[i] = t % 10;
        carry = t / 10;
    }

    while (carry)
    {
        b.digits[b.len++] = carry % 10;
        carry /= 10;
    }
}

int main()
{
	char buf[32];

	scanf("%s", buf);

	int len = strlen(buf);

	for (int i = 0; i < len; i++)
		num.push_back(buf[i] - '0');

	scanf("%d", &K);

	for (int i = 0; i < K; i++)
	{
		int s, t;
		scanf("%d %d", &s, &t);
		mapping[s].insert(t);
	}

	bign res;
	res.digits[0] = 1;

	for (int i = 0; i < num.size(); i++)
    {
        fill_n(canbe, 10, false);

        dfs(num[i]);

        int s = 0;
        for (int j = 0; j <= 9; j++)
            if (canbe[j])
                s++;
        //printf("%d\n", s);
        mul(res, s);
    }

    for (int i = res.len - 1; i >= 0; i--)
        printf("%d", res.digits[i]);

	return 0;
}
