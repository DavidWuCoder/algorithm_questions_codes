#include <bits/stdc++.h>
#include <cmath>
#define int long long

int  check(int x)
{
    for (int j = 2; j <= sqrt(x); j++)
    {
        if (x % j == 0)
        {
            return false;
        }
    }
    return true;
}

void solve(int& T)
{
    int n = 2025;
    int cnt = 0;
    for (int i = 2;; i++)
    {
        if (check(i))
        {
            // std::cout << i << ' ';
            cnt++;
        }
        if (cnt == 2025)
        {
            std::cout << i << ' ';
            break;
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