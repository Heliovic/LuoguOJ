#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N, K;

string str;
string ans = "0";
//map<string, map<string, string> > mp;

string add(string s1, string s2)
{
    string res = "";
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    if (s1.size() < s2.size())
        swap(s1, s2);

    int carry = 0;

    for (int i = 0; i < s2.size(); i++)
    {
        int t = s1[i] - '0' + s2[i] - '0' + carry;
        carry = t / 10;
        t %= 10;
        res += (char) t + '0';
    }

    for (int i = s2.size(); i < s1.size(); i++)
    {
        int t = s1[i] - '0' + carry;
        carry = t / 10;
        t %= 10;
        res += (char) t + '0';
    }

    if (carry)
        res += (char) carry + '0';

    reverse(res.begin(), res.end());

    return res;
}

string mul(string s1, string s2)
{
    /*if (mp.find(s1) != mp.end() && mp[s1].find(s2) != mp[s1].end())
        return mp[s1][s2];*/
    string res = "0";
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    for (int i = 0; i < s1.size(); i++)
    {
        string tmp = "";
        int carry = 0;
        int digit1 = s1[i] - '0';
        for (int j = 0; j < s2.size(); j++)
        {
            int t = digit1 * (s2[j] - '0') + carry;
            carry = t / 10;
            t %= 10;
            tmp += (char) (t + '0');
        }
        if (carry)
            tmp += (char) (carry + '0');
        reverse(tmp.begin(), tmp.end());

        for (int j = 0; j < i; j++)
            tmp += "0";

        res = add(res, tmp);
    }
    //mp[s1][s2] = res;
    return res;
}

bool gt(string& s1, string& s2)
{
    if (s1.size() != s2.size())
        return s1.size() > s2.size();

    for (int i = 0; i < s1.size(); i++)
        if (s1[i] != s2[i])
        {
            if (s1[i] > s2[i])
                return true;
            else
                return false;
        }

    return false;
}

void dfs(string& prev_res, int prev_sz, int prev_ptr)
{
    if (prev_sz == K)
    {
        string tmp = str.substr(prev_ptr + 1, str.size() - prev_ptr - 1);
        //cout << tmp << endl;
        string res = mul(prev_res, tmp);
        if (gt(res, ans))
            ans = res;
        //cout << ans << endl;
        return;
    }

    for (int i = prev_sz == 0 ? 0 : prev_ptr + 1; i < N - (K - prev_sz); i++)
    {
        string tmp = str.substr(prev_ptr + 1, i - prev_ptr);
        //cout << tmp << endl;
        string res = mul(prev_res, tmp);
        dfs(res, prev_sz + 1, i);
    }
}

int main()
{
    //ios::sync_with_stdio(false);

    cin >> N >> K;

    cin >> str;

    string t = "1";

    dfs(t, 0, -1);

    cout << ans;

    return 0;
}
