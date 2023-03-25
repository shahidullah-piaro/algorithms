#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int adjMatrix[n][n];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
            adjMatrix[i][j] = 0;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>adjMatrix[i][j];
        }
    }
    cout<<"-----------"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<i<<" : ";
        for(int j=0; j<n; j++)
        {
            if(adjMatrix[i][j] == 1)
            {
                cout << j << " ";
            }
        }
        cout<<endl;
    }
    return 0;
}
