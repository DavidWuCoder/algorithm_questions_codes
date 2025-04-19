#include <bits/stdc++.h>
#define int long long
const int N = 1e5 + 5;

std::vector<int> tree[N];

int w[N][31];
int dep[N];
int f[N][31];
int n, m;

void dfs(int u, int fa)
{
    f[u][0] = fa;
    dep[u] = dep[f[u][0]] + 1;
    w[u][0] = tree[u].size();
    for (int i = 1; i < 31; i++)
    {
        f[u][i] = f[f[u][i - 1]][i - 1];
        w[u][i] = w[u][i - 1] + w[f[u][i - 1]][i - 1];
    }
    for (int v : tree[u])
    {
        if (v == fa)
        {
            continue;
        }
        dfs(v, u);
    }
}

int lca(int x, int y)
{
    int res = 0;
    if (dep[x] > dep[y])
    {
        std::swap(x, y);
    }
    for (int j = 30; j >= 0; j--)
    {
        // 注意大于等于
        if (dep[f[y][j]] >= dep[x])
        {
            res += w[y][j];
            y = f[y][j];
        }
    }
    if (x == y)
    {
        res += w[y][0];
        return res;
    }
    for (int j = 30; j >= 0; j--)
    {
        if (f[x][j] != f[y][j])
        {
            res += w[x][j];
            res += w[y][j];
            x = f[x][j];
            y = f[y][j];

        }
    }
    res += (w[x][0] + w[y][1]);
    return res;
}

void solve(int &T)
{
    std::cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        std::cout << lca(u, v) << '\n';
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