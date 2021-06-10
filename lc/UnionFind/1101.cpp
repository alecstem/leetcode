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
    int earliestAcq(vector<vector<int>>& logs, int n) {
        UF uf(n);
        auto compare = [](vector<int> &a, vector<int> &b){ return a[0] < b[0]; };
        sort(logs.begin(), logs.end(), compare);
        for (int i = 0; i < logs.size(); ++i)
        {
            uf.join(logs[i][1], logs[i][2]);
            if (uf.size(0)==n) return logs[i][0];
        }
        return -1;
    }
};
