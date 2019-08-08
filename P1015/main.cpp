#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int sys;

struct bign
{
    vector<int> nums;

    bool check()
    {
        for (int i = 0; i < nums.size() / 2; i++)
            if (nums[i] != nums[nums.size() - 1 - i])
                return false;
        return true;
    }

    void add()
    {
        vector<int> tmp = nums;
        reverse(tmp.begin(), tmp.end());

        int carry = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int t = nums[i] + tmp[i] + carry;
            nums[i] = t % sys;
            carry = t / sys;
        }

        if (carry)
            nums.push_back(carry);
    }
};

int main()
{
    scanf("%d", &sys);
    char buf[256];
    scanf("%s", buf);

    int len = strlen(buf);
    bign num;

    for (int i = 0; i < len; i++)
    {
        char ch = buf[i];
        if (ch >= '0' && ch <= '9')
            num.nums.push_back(ch - '0');
        else
            num.nums.push_back(ch - 'A' + 10);
    }

    reverse(num.nums.begin(), num.nums.end());

    int step = 0;

    while (step < 30)
    {
        step++;
        num.add();
        if (num.check())
        {
            printf("STEP=%d", step);
            return 0;
        }
    }

    printf("Impossible!");

    return 0;
}
