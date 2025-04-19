#include <bits/stdc++.h>
#define int long long

const int N = 1e5 + 5;

int n, m;
std::vector<int> tree[N];

int f[N][32];
int w[N][32];
int dep[N];
void dfs(int u, int fa)
{
    f[u][0] = fa;
    dep[u] = dep[fa] + 1;
    for (int i = 1; i <= 30; i++)
    {
        f[u][i] = f[f[u][i - 1]][i - 1];
        w[u][i] += w[fa][i];
    }
    for (auto v : tree[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
    }
}

int lca(int x, int y)
{
    if (dep[x] > dep[y])
    {
        std::swap(x, y);
    }
    for (int j = 30; j >= 0; j--)
    {
        if (dep[f[y][j]] >= dep[x])
        {
            y = f[y][j];
        }
    }
    if (x == y)
    {
        return x;
    }
    for (int j = 30; j >= 0; j--)
    {
        if (f[y][j] != f[x][j])
        {
            x = f[x][j];
            y = f[y][j];
        }
    }
    return f[x][0];
}

void solve(int &T)
{
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        std::cin >> x;
        w[i][x] = 1;
    }
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
        int a, b;
        int ans = 0;
        std::cin >> a >> b;
        int L = lca(a, b);
        for (int i = 1; i <= 20; i++)
        { // 这个是遍历这一条路径能买到多少种i这个零食
            int num = w[a][i] + w[b][i] - w[L][i] - w[f[L][0]][i];
            /*起始节点到根节点能买到i种零食的个数 + 终点到根节点能买到i种零食的个数
              - 公共祖先到根节点能买到i种零食的个数- 公共祖先上一个节点到根节点能买到i种零食的个数
            */
            if (num)
                ans++; // 这个是看有没有这种零食出现
        }
        std::cout << ans << '\n';
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