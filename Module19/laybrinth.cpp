#include <bits/stdc++.h>
using namespace std;
const int maxN = 1010;
char grid[maxN][maxN];
bool visited[maxN][maxN];
int room;
int lennn;
vector<pair<int, int>> monstar;
pair<int, int> parent[maxN][maxN];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
char dir[4] = { 'D','R','U','L' };

void bfs(int x, int y, int n, int m)
{
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = true;
    parent[x][y] = { -1,-1 };
    while (!q.empty())
        while (!q.empty())
        {
            pair<int, int> u = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int dx_, dy_;
                dx_ = u.first + dx[i];
                dy_ = u.second + dy[i];
                if (dx_ >= 1 && dx_ <= n && dy_ >= 1 && dy_ <= m && !visited[dx_][dy_] && grid[dx_][dy_] == '.')
                {
                    visited[dx_][dy_] = true;
                    q.push({ dx_,dy_ });
                    parent[dx_][dy_] = u;
                }
            }

        }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int start_x, start_y, end_x, end_y;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == '.')
            {
                monstar.push_back({i,j});
            }
        }
    }
    start_x = 2;
    start_y = 5;
    bfs(start_x,start_y,n,m);
    room++;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(parent[i][j].first && parent[i][j].second !=0)
            {
                lennn++;
            }
        }
    }


    for(int i=0; i<monstar.size(); i++)
    {
        if(!visited[monstar[i].first][monstar[i].second])
        {
            bfs(monstar[i].first,monstar[i].second,n,m);
            room++;
        }
    }
    cout<<"Rooms - "<<room<<endl;
    cout<<"Length of the longest room - "<<lennn<<endl;
    return 0;
}
