#include <bits/stdc++.h>
#define int long long

const int N = 15;
int dp[N][N];
int num[N], now;

int dfs(int pos, int sum, bool lead, bool limit)
{
    int ans = 0;
    if (pos == 0)
    {
        return sum;
    }
    if (!lead && !limit && dp[pos][sum] != -1)
    {
        return dp[pos][sum];
    }
    int up = (limit ? num[pos] : 9);
    for (int i = 0; i <= up; i++)
    {
        if (i == 0 && lead)
            ans += dfs(pos - 1, sum, true, limit && i == up);
        else if (i == now)
            ans += dfs(pos - 1, sum + 1, false, limit && i == up);
        else if (i != now)
        {
            ans += dfs(pos - 1, sum, false, limit && i == up);
        }
    }
    if (!lead && !limit)
        dp[pos][sum] = ans;
    return ans;
}

int sol(int x)
{
    int len = 0;
    while (x)
    {
        num[++len] = x % 10;
        x /= 10;
    }
    memset(dp, -1, sizeof(dp));
    return dfs(len, 0, true, true);
}

void solve(int& T)
{
    int a, b;
    std::cin >> a >> b;
    for (int i = 0; i < 10; i++)
    {
        now = i;
        std::cout << sol(b) - sol(a - 1) << ' ';
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