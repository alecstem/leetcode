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
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        //uf all pairs, then iterate through both sentences and if words differ check grouping
        int n = max(similarPairs.size()*2+1, sentence1.size()+1);
        if (sentence1.size()!=sentence2.size()) return false;
        UF uf(n);
        unordered_map<string, int> m;
        int idx = 0;
        for (int i = 0; i < sentence1.size(); ++i)
        {
            if (m.find(sentence1[i])==m.end())
                m[sentence1[i]]=idx, idx++;
            if (m.find(sentence2[i])==m.end())
                m[sentence2[i]]=idx, idx++;
        }
        for (auto &e: similarPairs)
        {
            if (m.find(e[0])==m.end())
                m[e[0]]=idx, idx++;
            if (m.find(e[1])==m.end())
                m[e[1]]=idx, idx++;
        }
        for (auto &e: similarPairs)
            uf.join(m[e[0]], m[e[1]]);
        for (int i = 0; i < sentence1.size(); ++i)
            if (sentence1[i]!=sentence2[i]&&(uf.find(m[sentence1[i]])!=uf.find(m[sentence2[i]])))
                 return false;
        return true;
    }
};
