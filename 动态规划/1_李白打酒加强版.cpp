#include <bits/stdc++.h>
using ll = long long;
int n, m;
const ll mod = 1e9 + 7;

const int N = 105;
int f[N][N][N];

ll dfs(int x, int y, int s)
{

    if (x < 0 || y < 0 || s < 0) {
        return 0;
    }
    if (s > y) {
        return 0;
    }

    if (f[x][y][s] != -1) {
        return f[x][y][s];
    }

    if (x == 0 && y == 1 & s == 1) {
        return f[x][y][s] = 1;
    }

    return f[x][y][s] = (dfs(x - 1, y, s * 2) + dfs(x, y - 1, s - 1)) % mod;
}

void solve(int& T)
{
    memset(f, -1, sizeof(f));
    std::cin >> n >> m;
    std::cout << dfs(n, m, 2);
}

int main()
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