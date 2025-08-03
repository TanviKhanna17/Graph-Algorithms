#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

bool dfs(int src, int parent, vector<int>& vis, vector<int> adj[])
{
    vis[src] = 1;

    for (auto it : adj[src])
    {
        if (!vis[it])
        {
            if (dfs(it, src, vis, adj)) return true;
        }
        // If the node is previously visited but is not the parent of current 
        // node then it is being visited again hence cycle
        else if (it != parent) return true;
    }
    return false;
}


bool hasCycle(int N, vector<int> adj[])
{
    vector<int> vis(N, 0);
    for (int i = 0;i < N;i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, vis, adj)) return true;
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
        adj[v].push_back(u);
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