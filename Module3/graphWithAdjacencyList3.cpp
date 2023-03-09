#include<bits/stdc++.h>

using namespace std;

int main()
{
    int nodes = 4;
    vector<int>adjList[nodes];

    adjList[0] = {1};
    adjList[1] = {0, 2, 3};
    adjList[2] = {1, 3};
    adjList[3] = {1, 2};

    for(int i=0;i<nodes;i++)
    {
        cout<<i<<" --> ";
        for(int j=0;j<adjList[i].size();j++)
        {
            cout<<adjList[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
