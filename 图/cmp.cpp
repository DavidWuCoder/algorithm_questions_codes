#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> a(n + 1);
    vector<long long> dist(n + 1, INF);
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> pq;
    dist[1] = 0;
    pq.push(make_pair(0, 1));
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back(make_pair(v, w));
    }
    while (!pq.empty())
    {
        long long k = pq.top().second;
        int distk = pq.top().first;
        pq.pop();
        if (distk > dist[k])
            continue;
        for (int i = 0; i < a[k].size(); ++i)
        {
            long long knext = a[k][i].first;
            int aknext = a[k][i].second;
            if (dist[knext] > dist[k] + aknext)
            {
                dist[knext] = dist[k] + aknext;
                pq.push(make_pair(dist[knext], knext));
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (dist[i] >= INF)
            cout << -1 << " ";
        else
            cout << dist[i] << " ";
    }
    // 请在此输入您的代码
    return 0;
}