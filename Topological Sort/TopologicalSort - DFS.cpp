#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

// INTUITION 

// Linear Ordering on vertices such that if there is an edge b/w u & v
// 'u' appears before 'v' in the ordering
// This will only be possible on a DAG
// Since in a Cyclic Graph, two numbers can be before and after hence not possible

// ----------------------------------------------------------------------------------------------------

// APPROACH => USING DFS

// STEP 1 : MAINTAIN A VISITED ARRAY AND A STACK TO STORE THE ORDER
// STEP 2 : PERFORM DFS FOR ALL NODES 
// STEP 3 : IF !VIS MARK VIS AND PUSH INTO STACK AND CALL DFS FOR ITS CHILDREN
// STEP 4 : POP OUT STACK FOR THE TRAVERSAL

// ------------------------------------------------------------------------------

void dfs(int node, stack<int>& st, vector<bool>& vis, vector<int> adj[])
{
    vis[node] = true;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, st, vis, adj);
        }
    }
    st.push(node);
}

vector<int> TopoSort(int n, vector<int> adj[])
{
    vector<bool> vis(n, false);
    stack<int> st;
    for (int i = 0;i < n;i++)
    {
        if (!vis[i])
        {
            dfs(i, st, vis, adj);
        }

    }
    vector<int> ans;

    while (!st.empty())
    {
        int num = st.top();
        st.pop();
        ans.push_back(num);
    }

    return ans;
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

    vector<int> ans = TopoSort(n, adj);
    for (auto it : ans)
    {
        cout << it << " ";
    }

}