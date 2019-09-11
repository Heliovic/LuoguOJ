#include <cstdio>
#include <cstring>

#define MAX_N 64

using namespace std;

struct node
{
    char data;
    node* lc;
    node* rc;

    node() { lc = rc = NULL; }
};

char inorder[MAX_N];
char postorder[MAX_N];

node* create(int il, int ir, int pl, int pr)
{
    if (il > ir || pl > pr)
        return NULL;

    node* r = new node;
    r->data = postorder[pr];

    int k;

    for (int i = il; i <= ir; i++)
        if (inorder[i] == r->data)
        {
            k = i;
            break;
        }

    r->lc = create(il, k - 1, pl, pl + k - il - 1);
    r->rc = create(k + 1, ir, pl + k - il, pr - 1);
    return r;
}

void pre(node* r)
{
    if (r == NULL)
        return;

    putchar(r->data);
    pre(r->lc);
    pre(r->rc);
}

int main()
{
    char buf[MAX_N];

    scanf("%s", buf);

    int len = strlen(buf);

    for (int i = 0; i < len; i++)
        inorder[i + 1] = buf[i];

    scanf("%s", buf);

    len = strlen(buf);

    for (int i = 0; i < len; i++)
        postorder[i + 1] = buf[i];

    node* root = create(1, len, 1, len);
    pre(root);
    return 0;
}
