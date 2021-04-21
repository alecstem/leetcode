class Solution {
public:
    // This may be inefficient space-wise, but it beat 100% of other submissions for run-time. 
    // I'm pretty sure this is not optimal at all, but it was fun to code nonetheless.
    vector<string> findWords(vector<string>& words) {
        map<string, int> m;
        set<int> s;
        vector<string> v, words2 = words;
        int i = 0;
        m["qwertyuiop"]=1;
        m["asdfghjkl"]=2;
        m["zxcvbnm"]=3;
        for (auto &e: words)
        {
            transform(e.begin(), e.end(), e.begin(), ::tolower);
            for (auto &n: e)
                for (auto &k: m)
                    if (k.first.find(n)!=string::npos)
                        s.insert((int)k.second);
            if (s.size()==1)
                v.push_back(words2[i]);
            s.clear();
            i++;
        }
        return v;
    }
};