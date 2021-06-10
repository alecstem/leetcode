class Solution {
public:
    struct UF {
        vector<int> e;
        UF(int n) : e(n, -1) {}
        int cnt = 0;
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int idx = 0;
        UF uf(accounts.size()+1);
        unordered_map<string, set<string>> m;
        unordered_map<string, int> firstSeen;
        vector<vector<string>> v;
        for (auto &e: accounts)
        {
            m[e[0]]={};
            if (firstSeen.find(e[0])==firstSeen.end()) firstSeen[e[0]]=idx;
            idx++;
        }
        for (int i = 0; i < accounts.size(); ++i)
        {
            set<string> s;
            for (int j = 1; j < accounts[i].size(); ++j)
            {
                if (m[accounts[i][0]].count(accounts[i][j])&&!s.count(accounts[i][j]))
                    uf.join(firstSeen[accounts[i][0]], i);
                m[accounts[i][0]].insert(accounts[i][j]);
                s.insert(accounts[i][j]);
            }
        }
        m.clear();
        for (int i = accounts.size()-1; i >= 0; --i)
        {
            set<string> s;
            for (int j = 1; j < accounts[i].size(); ++j)
            {
                if (m[accounts[i][0]].count(accounts[i][j])&&!s.count(accounts[i][j]))
                    uf.join(firstSeen[accounts[i][0]], i);
                m[accounts[i][0]].insert(accounts[i][j]);
                s.insert(accounts[i][j]);
            }
        }
        m.clear();
        for (int i = 0; i < accounts.size(); ++i)
        {
            for (int j = 1; j < accounts[i].size(); ++j)
                m[to_string(uf.find(i))].insert(accounts[i][j]);
        }
        idx = 0;
        for (auto &e: m)
        {
            vector<string> tmp;
            tmp.push_back(accounts[uf.find(stoi(e.first))][0]);
            if (e.second.size()>0)
                for (auto &x : e.second)
                    tmp.push_back(x);
            if (tmp.size()>0)
                v.push_back(tmp);
            ++idx;
        }
        return v;
    }
};
