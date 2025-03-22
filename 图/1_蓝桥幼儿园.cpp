#include <bits/stdc++.h>
#define int long long

void solve(int& T)
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> f(n + 1);
    for (int i = 0; i <= n; i++)
    {
        f[i] = i;
    }
    std::function<int(int)> root = [&](int x)
    {
        return  f[x] = (f[x] == x ? x : root(f[x]));
    };
    for (int i = 0; i < m; i++)
    {
        int op, x, y;
        std::cin >> op >> x >> y;
        if (op == 1)
        {
            f[root(x)] = root(f[y]);
        }
        if (op == 2)
        {
            bool flag = (root(x) == root(y));
            std::cout << (flag ? "YES" : "NO") << '\n';
        }
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