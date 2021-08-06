class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &board, queue<pair<int,int>> &q,vector<vector<bool>> &visited)
    {
        if (i<0||i>=board.size()||j<0||j>=board[0].size()||visited[i][j]||board[i][j]=='X')
            return;
        q.push({i,j});
        visited[i][j]=true;
        dfs(i+1,j,board,q,visited);
        dfs(i-1,j,board,q,visited);
        dfs(i,j+1,board,q,visited);
        dfs(i,j-1,board,q,visited);
    }
    bool bfs(queue<pair<int,int>> &q, vector<vector<char>> board)
    {
        vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                pair<int,int> top = q.front();
                q.pop();
                for (int x = 0; x < dirs.size(); ++x)
                {
                    int i = top.first+dirs[x][0];
                    int j = top.second+dirs[x][1];
                    if (i<0||i>=board.size()||j<0||j>=board[0].size())
                        return false;
                }
            }
        }
        return true;
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
        for (int i = 1; i < board.size()-1; ++i)
            for (int j = 1; j < board[i].size()-1; ++j)
                if (board[i][j]=='O'&&!visited[i][j])
                {
                    queue<pair<int,int>> q;
                    dfs(i,j,board,q,visited);
                    queue<pair<int,int>> tmp = q;
                    if (bfs(q,board))
                    {
                        int n = tmp.size();
                        while (n--)
                        {
                            pair<int,int> top = tmp.front();
                            tmp.pop();
                            board[top.first][top.second]='X';
                        }
                    }
                }
    }
};
