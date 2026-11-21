class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        vector<int> new_parent(n, -1);
        vector<int> last_seen(26, -1);

        
        function<void(int)> dfs_reparent = [&](int u) {
            int c = s[u] - 'a';
            int prev = last_seen[c];
            
            if (u > 0) {
                new_parent[u] = (prev != -1) ? prev : parent[u];
            }
            
            last_seen[c] = u;
            for (int v : adj[u]) {
                dfs_reparent(v);
            }
            last_seen[c] = prev; 
        };

        dfs_reparent(0);

       
        vector<vector<int>> new_adj(n);
        for (int i = 1; i < n; ++i) {
            new_adj[new_parent[i]].push_back(i);
        }

        vector<int> ans(n, 0);

        
        function<int(int)> dfs_size = [&](int u) -> int {
            int size = 1;
            for (int v : new_adj[u]) {
                size += dfs_size(v);
            }
            ans[u] = size;
            return size;
        };

        dfs_size(0);
        return ans;
    }
};
