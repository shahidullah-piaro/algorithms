#include <bits/stdc++.h>
using namespace std;
const int maxN = 1010;
char grid[maxN][maxN];
bool visited[maxN][maxN];
vector<pair<int, int>> monstar;
vector<pair<int, int>> path1;
vector<pair<int, int>> path2;
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
    {
        pair<int, int> u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int dx_, dy_;
            dx_ = u.first + dx[i];
            dy_ = u.second + dy[i];
            if (dx_ >= 1 && dx_ <= n && dy_ >= 1 && dy_ <= m && !visited[dx_][dy_] && grid[dx_][dy_] != '#')
            {
                visited[dx_][dy_] = true;
                if(grid[dx_][dy_] != 'M')
                {
                    q.push({ dx_,dy_ });
                }
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
            if (grid[i][j] == 'A')
            {
                start_x = i;
                start_y = j;
            }
            if (grid[i][j] == 'M')
            {
                monstar.push_back({i,j});
            }
        }
    }
    bfs(start_x, start_y, n, m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cout<< "{" <<parent[i][j].first<<","<<parent[i][j].second <<"}"<<" ";
        }
        cout<<endl;
    }
    cout<<"--------------------------"<<endl;
    for(int i=0; i<monstar.size(); i++)
    {
        cout<< "{" <<monstar[i].first<<","<<monstar[i].second <<"}" << " "<<endl;
    }
    cout<<"----------------------------"<<endl;


    vector<pair<int, int>> path;
    end_x = 4;
    end_y = 8;
    path.push_back({ end_x,end_y });
    int x = end_x, y = end_y;
    while (parent[x][y] != make_pair(-1, -1))
    {
        pair<int, int> p = parent[x][y];
        x = p.first, y = p.second;
        path.push_back({ x,y });
    }
    reverse(path.begin(), path.end());
    string ans;
    for (int i = 0; i < path.size() - 1; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int dx_, dy_;
            dx_ = path[i].first + dx[j];
            dy_ = path[i].second + dy[j];
            if (dx_ == path[i + 1].first && dy_ == path[i + 1].second)
            {
                ans.push_back(dir[j]);
                break;
            }
        }
    }
    if(ans.size()!=0)
        cout<<"YES"<<endl;
    cout << ans.size() <<endl;
    cout << ans << endl;
    return 0;
}
