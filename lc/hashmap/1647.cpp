class Solution {
public:
    int minDeletions(string str) {
        // store freq array
        // greedily reduce counts that match until 
        // count is unique (not found in set), repeat
        set<int> s;
        unordered_map<char, int> m;
        int ans = 0;
        for (auto &e: str) m[e]++;
        for (auto &e: m)
            if (!s.count(e.second)) s.insert(e.second);
            else 
            {
                int x = e.second;
                while (s.count(x)&&x>0)
                    ans++, x--;
                if (x) s.insert(x);
            }
        return ans;
    }
};