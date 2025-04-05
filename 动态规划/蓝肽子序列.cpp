#include <bits/stdc++.h>
#define int long long

void solve(int &T)
{
    std::string s1, s2;
    std::cin >> s1 >> s2;
    std::vector<std::string> a, b;
    int pre = 0;
    for (int i = 1; i < s1.size(); i++)
    {
        if (s1[i] <= 'Z' && s1[i] >= 'A')
        {
            a.push_back(s1.substr(pre, i - pre));
            pre = i;
        }
    }
    a.push_back(s1.substr(pre, s1.size() - pre));
    pre = 0;
    for (int i = 1; i < s2.size(); i++)
    {
        if (s2[i] <= 'Z' && s2[i] >= 'A')
        {
            b.push_back(s2.substr(pre, i - pre));
            pre = i;
        }
    }
    b.push_back(s2.substr(pre, s2.size() - pre));
    // for (auto& s : b)
    // {
    //     std::cout << s << '\n';
    // }
    // for (auto &s : a)
    // {
    //     std::cout << s << '\n';
    // }
    std::vector<std::vector<int>> f(a.size() + 1, std::vector<int>(b.size() + 1));
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i] == b[j])
            {
                f[i + 1][j + 1] = f[i][j] + 1;
            }
            else
            {
                f[i + 1][j + 1] = std::max(f[i + 1][j], f[i][j + 1]);
            }
        }
    }
    std::cout << f[a.size()][b.size()];
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    for (int i = 1; i <= T; i++)
        solve(T);
    return 0;
}