class Solution {
public:
    vector<vector<int>> g;
    vector<bool> vis;
    int vertices, edges;

    void dfs(int v) {
        vis[v] = true;
        vertices++;
        edges += g[v].size();

        for (int child : g[v]) {
            if (!vis[child]) {
                dfs(child);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edgesList) {
        g.assign(n, {});
        vis.assign(n, false);

        for (auto &e : edgesList) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vertices = 0;
                edges = 0;
                dfs(i);
                edges /= 2;
                if (edges == vertices * (vertices - 1) / 2) {
                    ans++;
                }
            }
        }
        return ans;
    }
};