#include<bits/stdc++.h>

using namespace std;

//Time Complexity : O(1) + O(n^2) + O(n^2) = O(n^2)
//Space Complexity :

int main()
{
    int nodes = 4; //time complexity : O(1), space complexity : O(1)
    vector<pair<int,int>>adjList[nodes]; //time complexity : O(1), space complexity : O(n)

    //time complexity and space complexity : O(E * 2) -> O(E) -> worst case : O(n^2)
    /*
    adjList[0].push_back({1, 2});
    adjList[1].push_back({2, 4});
    adjList[3].push_back({2, 8});
    adjList[3].push_back({1, 7});
    */
    adjList[0] = {{1,2}};
    adjList[1] = {{2,4}};
    adjList[2] = {};
    adjList[3] = {{2,8},{1,7}};
    //time complexity : O(E * 2) -> O(E) -> worst case : O(n^2), space complexity : O(1)
    for(int i=0;i<nodes;i++)
    {
        cout<<i<<" --> ";
        for(int j=0;j<adjList[i].size();j++)
        {
            cout<<"( "<<adjList[i][j].first<<", "<<adjList[i][j].second<<"), ";
        }
        cout<<endl;
    }
    return 0;
}

