class Solution {
private:
    vector<vector<int>> adj, radj;
    vector<bool> vis;
    vector<int> stk;

    void dfs1(int u) {
        vis[u] = true;
        for (int v : adj[u])
            if (!vis[v]) dfs1(v);
        stk.push_back(u);
    }

    void dfs2(int u) {
        vis[u] = true;
        for (int v : radj[u])
            if (!vis[v]) dfs2(v);
    }

public:
    int kosaraju(int V, vector<vector<int>>& edges) {
        adj.assign(V, {});
        radj.assign(V, {});

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            radj[v].push_back(u);
        }

        /* Pass 1: fill finish-order stack */
        vis.assign(V, false);
        for (int i = 0; i < V; i++)
            if (!vis[i]) dfs1(i);

        /* Pass 2: DFS on transposed in reverse finish order */
        vis.assign(V, false);
        int scc = 0;
        while (!stk.empty()) {
            int u = stk.back(); stk.pop_back();
            if (!vis[u]) {
                dfs2(u);
                scc++;
            }
        }
        return scc;
    }
};
