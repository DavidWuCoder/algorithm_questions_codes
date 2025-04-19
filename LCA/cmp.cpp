#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int c[N][30];        // 表示到达第i颗星球种类j的数量
int dep[N];          // 深度
int fa[N][30];       // 存储i节点的2^j次方的父节点是谁
vector<int> node[N]; // 存储节点的

void dfs(int x, int f)
{ // 传入当前节点和父节点
    for (int i = 1; i <= 20; i++)
    {
        c[x][i] += c[f][i]; // 让当前节点加上父亲节点每个种类
    }
    dep[x] = dep[f] + 1;
    fa[x][0] = f;
    for (int i = 1; i <= 20; i++)
    {
        fa[x][i] = fa[fa[x][i - 1]][i - 1]; // 求2^j次方的父节是谁
    }
    for (auto j : node[x])
    {
        if (j == f)
            continue; // 因为建立了双向边 所以要把父节点给跳过
        dfs(j, x);
    }
}

int Lca(int s, int t)
{
    if (dep[s] < dep[t])
        swap(s, t); // 保证s的深度是更深的
    for (int i = 20; i >= 0; i--)
    {
        if (dep[fa[s][i]] >= dep[t])
            s = fa[s][i]; // 如果跳到的深度比要找的t的深度还深就跳过去
    }
    if (s == t)
        return s;
    for (int i = 20; i >= 0; i--)
    {
        if (fa[s][i] != fa[t][i])
        { // 跳到的不是同一个节点的时候才往上跳
            s = fa[s][i];
            t = fa[t][i];
        }
    }
    return fa[s][0];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        c[i][x] = 1; // 初始化第i颗星球的x种零食数量为1
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u); // 建立双向边
    }
    dfs(1, 0);
    while (q--)
    {
        int s, t, ans = 0;
        cin >> s >> t;
        int lca = Lca(s, t); // 返回的是公共的祖先
        for (int i = 1; i <= 20; i++)
        { // 这个是遍历这一条路径能买到多少种i这个零食
            int num = c[s][i] + c[t][i] - c[lca][i] - c[fa[lca][0]][i];
            /*起始节点到根节点能买到i种零食的个数 + 终点到根节点能买到i种零食的个数
              - 公共祖先到根节点能买到i种零食的个数- 公共祖先上一个节点到根节点能买到i种零食的个数
            */
            if (num)
                ans++; // 这个是看有没有这种零食出现
        }
        cout << ans << "\n";
    }
    return 0;
}