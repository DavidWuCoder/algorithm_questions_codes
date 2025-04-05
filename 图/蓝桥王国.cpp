#include <bits/stdc++.h>
#define int long long
const int inf = 1e18;

void solve(int &T)
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> g(n + 1);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, 1});
    std::vector<int> dis(n + 1, inf);
    dis[1] = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    while (!pq.empty())
    {
        auto dx = pq.top().first;
        auto x = pq.top().second;
        pq.pop();
        if (dx > dis[x])
        {
            continue;
        }
        dis[x] = dx;
        for (auto edge : g[x])
        {
            int dy = edge.second;
            int y = edge.first;
            int new_dis = dx + dy;
            if (new_dis < dis[y])
            {

                dis[y] = new_dis;
                pq.push({dis[y], y});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int x = dis[i];
        std::cout << (x == inf ? -1 : x) << ' ';
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