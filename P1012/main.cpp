#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;

bool cmp(string& s1, string& s2)
{
    if (s1 + s2 > s2 + s1)
        return true;
    return false;
}

int main()
{
    cin >> N;

    vector<string> strs;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        strs.push_back(s);
    }

    sort(strs.begin(), strs.end(), cmp);

    for (int i = 0; i < N; i++)
        cout << strs[i];

    return 0;
}
