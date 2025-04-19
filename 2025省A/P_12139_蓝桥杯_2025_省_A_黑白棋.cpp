#include <bits/stdc++.h>
#define int long long

char a[37][37];

void init()
{
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            a[i][j] = '#';
        }
    }
    a[1][1] = '1';
    a[5][3] = '1';
    a[5][6] = '1';
    a[6][5] = '1';
    a[1][2] = '0';
    a[1][4] = '0';
    a[2][4] = '0';
    a[3][5] = '0';
    a[3][6] = '0';
    a[6][2] = '0';
}

bool full()
{
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (a[i][j] == '#')
                return false;
        }
    }
    return true;
}

bool inrange(int x)
{
    if (x < 1 || x > 6)
    {
        return false;
    }
    return true;
}

bool check(int x, int y, char flag)
{
    int x1 = x + 1;
    int x2 = x + 2;
    int x3 = x - 1;
    int x4 = x - 2;
    if (inrange(x1))
    {
        if (a[x1][y] == flag)
        {
            if (inrange(x2))
            {
                if (a[x2][y] == flag)
                {
                    return false;
                }
            }
            if (inrange(x3))
            {
                if (a[x3][y] == flag)
                {
                    return false;
                }
            }
        }
    }
    if (inrange(x3) && inrange(x4))
    {
        if (a[x3][y] == flag && a[x4][y] == flag)
        {
            return false;
        }
    }
    int y1 = y + 1;
    int y2 = y + 2;
    int y3 = y - 1;
    int y4 = y - 2;
    if (inrange(y1))
    {
        if (a[x][y1] == flag)
        {
            if (inrange(y2))
            {
                if (a[x][y2] == flag)
                {
                    return false;
                }
            }
            if (inrange(y3))
            {
                if (a[x][y3] == flag)
                {
                    return false;
                }
            }
        }
    }
    if (inrange(y3) && inrange(y4))
    {
        if (a[x][y3] == flag && a[x][y4] == flag)
        {
            return false;
        }
    }
    return true;
}

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

bool dfs(int x, int  y)
{
    if (full())
    {
        std::set<std::string> row;
        for (int i = 1; i <= 6; i ++)
        {
            std::string s = "";
            for (int j = 1; j <= 6; j++)
            {
                s += a[i][j];
            }
            if (row.find(s) != row.end())
            {
                row.insert(s);
            }
            else
            {
                return false;
            }
        }
        std::set<std::string> col;
        for (int i = 1; i <= 6; i++)
        {
            std::string s = "";
            for (int j = 1; j <= 6; j++)
            {
                s += a[j][i];
            }
            if (col.find(s) != col.end())
            {
                col.insert(s);
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if  (nx <= 0 || nx > 6 || ny <= 0 || ny > 6)
            continue;
        if (a[nx][ny] != '#')
            continue;
        if (check(x, y, '0'))
        {
            a[nx][ny] = '1';
            if (dfs(nx, ny))
                return true;
            a[nx][ny] = '#';
        }
        if (check(x, y, '0'))
        {
            a[nx][ny] = '0';
            if (dfs(nx, ny))
                return true;
            a[nx][ny] = '#';
        }
    
    }

}

void solve(int& T)
{
    init();
    dfs(1, 3);
    // for (int i = 1; i <= 6; i++)
    // {
    //     for (int j = 1; j <= 6; j++)
    //     {
    //         std::cout << a[i][j] << ' ';
    //     }
    //     std::cout << '\n';
    // }
    
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