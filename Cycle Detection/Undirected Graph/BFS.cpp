#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

bool detectCycle(int src, vector<int>& vis, vector<int> adj[])
{
    vis[src] = 1;
    queue<pair<int, int>> q;

    // {Node, Parent}
    // Since start node has no parent -> -1
    q.push({ src, -1 });

    while (!q.empty())
    {
        auto it = q.front();
        int node = it.first;
        int parent = it.second;
        q.pop();


        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push({ it, node });
            }
            else if (parent != it) return true;

        }

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
            if (detectCycle(i, vis, adj)) return true;
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