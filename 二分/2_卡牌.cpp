#include <bits/stdc++.h>
#define int long long

void solve(int& T)
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    std::vector<int> b(n);
    for (int& i : a)
    {
        std::cin >> i;
    }
    for (int &i : b)
    {
        std::cin >> i;
    }
    std::sort(a.begin(), a.end());
    int mx = a.back();
    int r = mx + m / n;
    int l = 1;
    int ans = 0;

    std::function<bool(int)> check = [&](int mid)
    {
        int b_num = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < mid)
            {
                if (a[i] + b[i] < mid)
                {
                    return false;
                }
                b_num += mid - a[i];
            }
        }
        return b_num <= m;
    };

    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
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
    // std::cin >> T;
    for (int i = 1; i <= T; i++)
        solve(T);
    return 0;
}