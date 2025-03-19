#include <bits/stdc++.h>
#define int long long

struct ti
{
    int l, s;
};

void solve(int& T)
{
    int n, m;
    std::cin >> n >> m;
    std::vector<ti> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i].l >> a[i].s;
    }
    sort(a.begin(), a.end(), [](ti &n1, ti &n2)
                          { return n1.s < n2.s; });
    int ri = m - a.back().s + 1;
    int le = 0;
    int ans = 0;
    auto check = [&](int mid) -> bool
    {
        if (a[0].l - std::max(mid-a[0].s, (long long)0) > 1)
        {
            return false;
        }
        int prel = 0;
        int prer = a[0].l + std::max(mid - a[0].s, (long long)0);
        for (int i = 2; i < n; i++)
        {
            if (a[0].l - std::max(mid - a[0].s, (long long)0) > prer + 1)
            {
                return false;
            }
        }
        return (a[n - 1].l + std::max(mid - a[0].s, (long long)0)) >= m;

    };
    while (le <= ri)
    {
        int mid = (le + ri) >> 1;
        if (check(mid))
        {
            ri = mid - 1;
            ans = mid;
        }
        else
        {
            le = mid + 1;
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