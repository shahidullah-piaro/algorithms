#include<bits/stdc++.h>

using namespace std;

//Time Complexity : O(1) + O(n^2) + O(n^2) + O(n^2) = O(n^2)
//Space Complexity : O(1) + O(n^2) = O(n^2)

int main()
{
    int nodes = 4;
    //time complexity : O(1)
    //space complexity : O(1)

    int matrix[nodes][nodes]; //space complexity : O(n^2)

    for(int i=0; i<nodes; i++) //time complexity : O(n^2)
    {
        for(int j=0; j<nodes; j++)
            matrix[i][j] = 0;
    }

    matrix[0][1] = 1; //time complexity : O(E) -> edge, worst case : O(n^2)
    matrix[1][0] = 1;

    matrix[1][2] = 1;
    matrix[2][1] = 1;

    matrix[2][3] = 1;
    matrix[3][2] = 1;

    matrix[3][1] = 1;
    matrix[1][3] = 1;

    for(int i=0;i<nodes;i++) //time complexity : O(n^2)
    {
        for(int j=0;j<nodes;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

