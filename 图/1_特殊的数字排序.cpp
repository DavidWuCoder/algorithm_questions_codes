#include <bits/stdc++.h>
#define int long long

void solve(int &T)
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int& i : a)
        std::cin >> i;
    std::vector<int> f(n + 1);
    for (int i = 0; i <= n; i++)
    {
        f[i] = i;
    }
    std::function<int(int)> root = [&](int x)
    {
        return f[x] = (f[x] == x ? x : root(f[x]));
    };
    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        f[root(x)] = root(y);
    }
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