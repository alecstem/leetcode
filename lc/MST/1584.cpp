class Solution {
public:
    struct Node
    { 
        int x, y, dist;
        Node(int x, int y, int dist) : x(x), y(y), dist(dist) {}
    };
    struct UF {
        vector<int> e;
        int cnt = 0;
        UF(int n) : e(n, -1) {}
        bool sameSet(int a, int b) { return find(a) == find(b); }
        int size(int x) { return -e[find(x)]; }
        int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
        bool join(int a, int b) {
            a = find(a), b = find(b);
            if (a == b) return false;
            if (e[a] > e[b]) swap(a, b);
            e[a] += e[b]; e[b] = a; cnt++;
            return true;
        }
        int count() { return cnt; }
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        UF uf(n);
        auto compare = [](Node &a, Node &b){return a.dist > b.dist;};
        priority_queue<Node, vector<Node>, decltype(compare)> pq(compare);
        int ans = 0;
        for (int i = 0; i < n-1; ++i)
            for (int j = 1; j < n; ++j)
            {
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                Node node = Node(i,j,dist);
                pq.push(node);
            }
        while (!pq.empty())
        {
            Node top = pq.top();
            pq.pop();
            if (uf.join(top.x, top.y))
                ans+=top.dist;
            if (uf.count()==n-1)
                return ans;
        }
        return 0;
    }
};