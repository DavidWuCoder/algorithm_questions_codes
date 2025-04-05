#include <bits/stdc++.h>
#define int long long

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void solve(int &T)
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> g[n * m];
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                int u = i * m + j;
                int v = nx * m + ny;
                g[u].emplace_back(v, matrix[nx][ny]);
            }
        }
    }
    std::vector<int> dis(n * m, LLONG_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.emplace(matrix[0][0], 0);
    dis[0] = matrix[0][0];
    std::vector<bool> vis(n * m);
    while (!pq.empty())
    {
        int dx = pq.top().first;
        int x = pq.top().second;
        pq.pop();
        if (dx > dis[x])
        {
            continue;
        }
        vis[x] = true;
        dis[x] = dx;
        for (auto edge : g[x])
        {
            int y = edge.first;
            int dy = edge.second;
            int new_dis = dx + dy;
            if (new_dis < dis[y])
            {
                dis[y] = new_dis;
                pq.emplace(dis[y], y);
            }
        }
    }
    int a = 0;
    for (int &x : dis)
    {
        if (x != LLONG_MAX && x > a)
        {
            a = x;
        }
        // std::cout << x << ' ';
    }
    std::cout << a << '\n';
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