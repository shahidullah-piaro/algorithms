#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>> adjList[n+1];
    for(int i=1;i<=e;i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }
    for(int i=0;i<=n;i++)
    {
        cout<<i<<" --> ";
        for(auto j : adjList[i])
            cout << "{" << j.first << "," << j.second << "}" << " ";
        cout<<endl;
    }
    return 0;
}

