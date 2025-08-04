#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

// INTUITION 

// I EXPLORE ALL PATHS VIA DFS FOR ALL CONNECTED COMPONENTS
// IF I REACH A PREVIOUSLY VISITED NODE ON THE SAME PATH
// THEN A CYCLE EXISTS

// ----------------------------------------------------------------------------------------------------

// APPROACH

// ALGORITHM ->
// STEP 1 : Perform DFS on All Connected Components
// STEP 2 : Create 2 vectors :
//            |-> 1) visited = Keeps Track of all the nodes that are yet to visit for DFS
//            |-> 2) Path_visited = Keeps Track of all nodes that were visited on the current path
// STEP 3 : For curr Node for which DFS is called -> mark it as visited
// Then call for the adjacent Node
// Here 3 cases can be formed for the adj Node:
//            |-> 1) Node is Not Visited : Make New DFS Call
//            |-> 2) Node is Visited but not On same Path : Mark as path_visited and go to next adj node
//            |-> 3) Node is Visited and Also Path_Visited : return true that cycle exists
// STEP 4 : Finally if no new nodes to viist , unmark all the nodes in path_visited and return false
// At end of traversal unmark all path_visited Nodes

// ------------------------------------------------------------------------------

bool checkDFSCycle(int node, vector<bool>& visited, vector<bool>& path_visited, vector<int> adj[])
{
    visited[node] = true;
    path_visited[node] = true;

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            if (checkDFSCycle(it, visited, path_visited, adj) == true) return true;
        }
        else if (path_visited[it] == true) return true;
    }
    path_visited[node] = 0;
    return false;
}

bool hasCycle(int n, vector<int> adj[])
{
    vector<bool> visited(n, false);
    vector<bool> path_visited(n, false);
    for (int i = 0;i < n;i++)
    {
        if (!visited[i])
        {
            if (checkDFSCycle(i, visited, path_visited, adj) == true) return true;
        }
    }
    return false;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // No of nodes and edges
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];

    for (int i = 0;i < m;i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    if (hasCycle(n, adj))
    {
        cout << "Graph has cycle";
    }
    else
    {
        cout << "Graph does not contain cycle";
    }
}