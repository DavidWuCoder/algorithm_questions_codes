#include <bits/stdc++.h>
#define int long long

struct stu
{
    int id;
    int cnt;
    int q;
};

void solve(int& T)
{
    int n;
    std::cin >> n;
    std::vector<stu> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i].cnt;
        a[i].id = i;
        a[i].q = 0;
    }
    sort(a.begin(), a.end(), [](stu &n1, stu& n2)
         { return n1.cnt < n2.cnt; });
    int x;
    if (n % 2 == 1)
    {
        x = a[n / 2].cnt + 1;
    }
    else
    {
        x = a[n / 2].cnt;
    }
    for (int i = 0; i < n / 2; i++)
    {
        a[i].q = x - a[i].cnt;
    }
    sort(a.begin(), a.end(), [](stu &n1, stu &n2)
         { return n1.id < n2.id; });
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i].q << ' ';
    }
    std::cout << '\n';
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