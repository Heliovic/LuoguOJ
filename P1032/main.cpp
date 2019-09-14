#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <climits>
#include <algorithm>
#include <set>

using namespace std;

map<string, vector<string> > mp;
set<string> st;

string A, B;

int ans = INT_MAX;

void dfs(string cur_s, int level)
{
    if (st.find(cur_s) != st.end())
        return;

    if (level > 10 || level >= ans)
        return;

    for (map<string, vector<string> >::iterator it = mp.begin(); it != mp.end(); it++)
    {
        int p = 0;

        while ((p = cur_s.find(it->first, p)) != string::npos)
        {
            for (int i = 0; i < it->second.size(); i++)
            {
                string str = cur_s;
                str.replace(str.begin() + p, str.begin() + p + it->first.size(), it->second[i]);

                if (str == B)
                {
                    ans = level;
                    return;
                }

                dfs(str, level + 1);
            }
            p++;
        }
    }

    st.insert(cur_s);
}

int main()
{
    cin >> A >> B;

    string s1, s2;

    while (cin >> s1 >> s2)
    {
        if (mp.find(s1) == mp.end())
            mp[s1] = vector<string>();
        mp[s1].push_back(s2);
    }

    dfs(A, 1);

    if (ans != INT_MAX)
        cout << ans;
    else
        cout << "NO ANSWER!";

    return 0;
}
