#include <bits/stdc++.h>
#define int long long

int n, m, k;

void solve(int &T)
{
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> martix(n + 1, std::vector<int>(m + 1));
    std::vector<std::vector<int>> pre(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> martix[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + martix[i][j];
        }
    }
    if (pre[n][m] < k + 1)
    {
        std::cout << -1 << '\n';
        return;
    }
    std::function<bool(int)> check = [&](int mid)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int up = std::max(i - mid, (long long)1), left = std::max(j - mid, (long long)1);
                int down = std::min(i + mid, n), right = std::min(j + mid, m);
                int cnt = pre[down][right] - pre[down][left - 1] - pre[up - 1][right] + pre[up - 1][left - 1];
                if (cnt >= k + 1 && martix[i][j])
                {
                    return true;
                }
            }
        }
        return false;
    };
    int l = 0, r = std::max(n, m);
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    std::cout << ans << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    std::cin >> T;
    for (int i = 1; i <= T; i++)
        solve(T);
    return 0;
}