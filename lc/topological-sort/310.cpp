class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // base cases
        if (n<=2)
        {
            vector<int> v;
            for (int i = 0; i < n; ++i)
                v.push_back(i);
            return v;
        }
        unordered_map<int, vector<int>> adj;
        int k = n;
        vector<int> leaves;
        unordered_map<int, int> m;
        for (int i = 0; i < edges.size(); ++i)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        // store # of neighbors
        for (int i = 0; i < n; ++i)
        {
            int neighbors = adj[i].size();
            m[i]=neighbors;
            if (neighbors==1)
                leaves.push_back(i);
        }
        // top sort
        while (n>2)
        {
            vector<int> new_leaves;
            n-=leaves.size();
            // for each neighbor in each leaf
            for (auto &e : leaves)
                for (auto &x : adj[e])
                    if (--m[x]==1)
                        new_leaves.push_back(x);
            leaves = new_leaves;
        }
        return leaves;
    }
};