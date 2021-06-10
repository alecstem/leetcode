class Solution {
public:
    struct Node
    {
        int c1, c2, w;
        Node(int c1, int c2, int w) : c1(c1), c2(c2), w(w) {}
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
    int minimumCost(int n, vector<vector<int>>& connections) {
        UF uf(n+1);
        int ans = 0, cnt = 0;
        auto compare = [](Node &a, Node &b){return a.w > b.w;};
        priority_queue<Node, vector<Node>, decltype(compare)> pq(compare);
        for (int i = 0; i < connections.size(); ++i)
        {
            Node tmp = Node(connections[i][0], connections[i][1], connections[i][2]);
            pq.push(tmp);
        }
        while (!pq.empty())
        {
            Node top = pq.top();
            pq.pop();
            if (uf.join(top.c1, top.c2)) ans+=top.w, cnt++;
            if (cnt==n-1) return ans;
        }
        return -1;
    }
};
