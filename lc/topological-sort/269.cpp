class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        unordered_map<char, vector<char>> m;
        unordered_map<char, int> degree;
        set<char> initial;
        stack<char> s;
        string ans = "";
        for (auto &e: words)
            for (auto &x: e)
                initial.insert(x);
        for (int i = 1; i < n; ++i)
        {
            string word1 = words[i-1], word2 = words[i];
            int l1 = word1.length(), l2 = word2.length();
            if (l1>l2&&word1.substr(0, l2)==word2) return "";
            int x = 0, y = 0;
            while ((x<l1)&&(y<l2)&&word1[x]==word2[y])
                x++, y++;
            if (x<l1&&y<l2)
            {
                m[word1[x]].push_back(word2[y]);
                degree[word2[y]]++;
            }  
        }
        for (auto &e: initial)
            if (degree[e]==0)
                s.push(e);
        while (!s.empty())
        {
            char top = s.top();
            s.pop();
            ans+=top;
            for (auto &e: m[top])
                if (--degree[e]==0) s.push(e);
        }
        return (ans.length()==initial.size()) ? ans : "";
    }
};
