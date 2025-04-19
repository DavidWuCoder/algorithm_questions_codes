#include <bits/stdc++.h>
#define int long long

const int MXN = 40005;
std::vector<int> v[MXN];
std::vector<int> w[MXN];

int fa[MXN][31], dep[MXN];
int n, m;
int a, b, c;

void dfs(int root, int fno)
{
    fa[root][0] = fno;
    dep[root] = dep[fa[root][0]] + 1;

    for (int i = 1; i < 31; i++)
    {
        fa[root][i] = fa[fa[root][i - 1]][i - 1];
    }
    int sz = v[root].size();
    for (int i = 0; i < sz; i++)
    {
        if (v[root][i] == fno)
            continue;
        dfs(v[root][i], root);
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
        if (dep[fa[y][j]] >= dep[x])
        {
            y = fa[y][j];
        }
    }
    if (x == y)
    {
        return x;
    }
    for (int j = 30; j >= 0; j--)
    {
        if (fa[x][j] != fa[y][j])
        {
            x = fa[x][j];
            y = fa[y][j];
        }
    }
    return fa[x][0];
}

void solve(int &T)
{
    memset(fa, 0, sizeof(fa));
    memset(dep, 0, sizeof(dep));

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        v[i].clear();
        w[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
        std::cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0);
    for (int i = 0; i < m; i++)
    {
        std::cin >> a >> b;
        std::cout << lca(a, b) << '\n';
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