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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UF uf(n+1);
        set<int> s;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (isConnected[i][j])
                    uf.join(i+1, j+1);
        return n-uf.count();
    }
};