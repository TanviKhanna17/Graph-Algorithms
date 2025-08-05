#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

vector<int> Dijkstras(int n, vector<vector<int>> adj[])
{
    // Maintains the shortest path as Set
    set<pair<int, int>> st;

    // Maintains all the shortest distances from the start position
    vector<int> dist(n, INT_MAX);

    // Put Starting node inside the set
    st.insert({ 0,0 });
    dist[0] = 0;


    // THE ACTUAL ALGORITHM:
    // STEP 1 : EXTRACT SMALLEST DISTANCE FROM THE SET
    // STEP 2 : FOR ALL ITS ADJACENT NODES, CHECK WHETHER THE NEW FOUND DIST IS BETTER THAN CURR DIST
    // STEP 3 : IF IT IS BETTER , UPDATE THE DIST ARRAY, AND ADD THE NEW DIST BACK TO THE SET TO REACH OTHER NODES A BETTER WAY
    // STEP 4 : KEEP UPDATING TILL ALL THE DIFFERENT DISTANCES HAVE BEEN CONVERED

    while (st.size() > 0)
    {
        auto it = *(st.begin());
        st.erase(it);
        int prev_dist = it.first;
        int node = it.second;

        for (auto k : adj[node])
        {
            int currEdgeWt = k[1];
            int nextNode = k[0];

            if (prev_dist + currEdgeWt < dist[nextNode])
            {
                dist[nextNode] = prev_dist + currEdgeWt;
                st.insert({ dist[nextNode],nextNode });
            }
        }
    }

    return dist;
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
    vector<vector<int>> adj[n];

    for (int i = 0;i < m;i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({ v,wt });
        adj[v].push_back({ u,wt });
    }

    vector<int> ans = Dijkstras(n, adj);
    for (auto it : ans)
    {
        cout << it << " ";
    }

}