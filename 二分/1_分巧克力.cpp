#include <bits/stdc++.h>
#define int long long

struct rec
{
    int a, b;
};

void solve(int& T)
{
    int n, m;
    std::cin >> n >> m;
    std::vector<rec> a(n);
    int r = 0;
    for (auto& i : a)
    {
        std::cin >> i.a >> i.b;
        r = std::max(r, i.a);
        r = std::max(r, i.b);
    }
    int l = 1;
    int ans = 0;

    std::function<bool(int)> check = [&](int mid)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            // int minl = std::min(a[i].a, a[i].b);
            cnt += (a[i].a / mid) * (a[i].b / mid);
        }
        return cnt >= m;
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