class Solution {
public:
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size()<n-1) return -1;
        int cnt = 0;
        int unconnected = 0;
        UF uf(n+5);
        for (int i = 0; i < connections.size(); ++i)
            uf.join(connections[i][0], connections[i][1]);
        for (int i = 0; i < n; ++i)
            if (uf.find(i)==i)
                unconnected++;
        return unconnected-1;
    }
};