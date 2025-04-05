#include <bits/stdc++.h>
#define int long long

void solve(int &T)
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    int sum = 0;
    for (int &i : a)
    {
        std::cin >> i;
        sum += i;
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        std::cin >> l >> r;
        if ((r - l) % 2 == 0)
        {
            sum += (r - (r - l) / 2);
        }
        else
        {
            sum -= (((r - l) + 1) / 2);
        }
    }
    std::cout << sum << '\n';
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