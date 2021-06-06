class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> degree;
        stack<int> s;
        vector<int> v;
        for (int i = 0; i < p.size(); ++i)
        {
            adj[p[i][1]].push_back(p[i][0]);
            degree[p[i][0]]++;
        }
        for (int i = 0; i < numCourses; ++i)
            if (degree[i]==0)
                s.push(i);
        while (!s.empty())
        {
            int node = s.top();
            s.pop();
            v.push_back(node);
            numCourses--;
            for (auto &e: adj[node])
            {
                degree[e]--;
                if (degree[e]==0)
                    s.push(e);
            }
        }
        if (!numCourses) return v;
        return {};
    }
};