// C++ program to check if there is exist a path between
// two vertices of an undirected graph.

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

// function to initialise
// the adjacency matrix
void init(int n)
{
	for(int i=1;i<=n;i++)
		adj[i][i]=1;
}

// Function to add edge between nodes
void addEdge(int a,int b)
{
	adj[a][b]=1;
	adj[b][a]=1;
}

// Function to compute the path
void computePaths(int n)
{
	// Use Floyd Warshall algorithm
	// to detect if a path exists
	for(int k = 1; k <= n; k++)
	{
		// Try every vertex as an
		// intermediate vertex
		// to check if a path exists
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				adj[i][j] = adj[i][j] | (adj[i][k] && adj[k][j]);
	}
}

// Function to check if nodes are reachable
bool isReachable(int s, int d)
{
	if (adj[s][d] == 1)
		return true;
	else
		return false;
}

// Driver Code
int main()
{
	int n = 8;
	adj = vector<vector<int>>(n+1,vector<int>(n+1,0));

	init(n);
/*
0 1
4 0
4 2
2 3
1 3
2 5
5 6
6 7
6 3
*/
	addEdge(0,1);
	addEdge(4,0);
	addEdge(4,2);
	addEdge(2,3);
	addEdge(1,3);
	addEdge(2,5);
	addEdge(5,6);
	addEdge(6,7);
	addEdge(6,3);

	computePaths(n);

	int u = 2, v = 7;
	if(isReachable(u,v))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}

