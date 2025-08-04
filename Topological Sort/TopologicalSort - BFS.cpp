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

// APPROACH => USING BFS / KAHN's ALGO

// STEP 1 : MAINTAIN AN ARRAY THAT STORES INDEGREE AND A QUEUE TO STORE THE ORDER
// STEP 2 : FOR ALL NODES WITH INDEGREE 0 , PUSH INTO QUEUE
// STEP 3 : START BFS FOR ALL CONNECTED COMPONENTS
// STEP 3 : GO TO ITS CHILDREN , REDUCE THEIR INDEGREE AND IF INDEGREE = 0 , ALSO PUSH THAT INTO QUEUE
// STEP 4 : KEEP PUSHING TAKEN OUT ELEMENTS IN A VECTOR FOR TRAVERSAL


// ------------------------------------------------------------------------------



vector<int> TopoSort(int n, vector<int> adj[])
{
    vector<int> inDegree(n, 0);
    queue<int> q;

    for (int i = 0;i < n;i++)
    {
        for (auto it : adj[i])
        {
            inDegree[it]++;
        }
    }

    for (int i = 0;i < n;i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;

    while (!q.empty())
    {
        auto node = q.front();
        ans.push_back(node);
        q.pop();

        for (auto it : adj[node])
        {
            inDegree[it]--;
            if (inDegree[it] == 0) q.push(it);
        }
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