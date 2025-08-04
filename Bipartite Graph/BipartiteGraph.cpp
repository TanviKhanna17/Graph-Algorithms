#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second


bool dfs(int node, int color, vector<int>& colors, vector<int> graph[])
{
    colors[node] = color;

    for (auto it : graph[node])
    {
        if (colors[it] == -1)
        {
            if (dfs(it, !color, colors, graph) == false) return false;
        }
        if (colors[it] == color) return false;
    }
    return true;
}

bool isBipartite(int n, vector<int> graph[])
{
    // Graph is given in form of adjacency List
    // Will be Bipartite only if can be coloured with 2 colours
    // int n = graph.size();

    vector<int> colors(n, -1);

    for (int i = 0;i < n;i++)
    {
        if (colors[i] == -1)
        {
            if (dfs(i, 0, colors, graph) == false) return false;
        }
    }
    return true;
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
        adj[v].push_back(u);
    }

    if (isBipartite(n, adj))
    {
        cout << "Graph is Bipartite";
    }
    else
    {
        cout << "Graph is not Bipartite";
    }
}