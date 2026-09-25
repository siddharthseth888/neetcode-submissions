class Solution {
public:
    void DFS(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis)
    {
        int m = board.size();
        int n = board[0].size();
        vis[row][col] = 1;
        vector<pair<int,int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};

        for(int i = 0; i < 4; i++)
        {
            int nr = row + dirs[i].first;
            int nc = col + dirs[i].second;

            if(nr >= 0 && nr < m && nc >= 0 && nc < n)
            {
                if(!vis[nr][nc] && board[nr][nc] == 'O')
                {
                    vis[nr][nc] = 1;
                    DFS(nr, nc, board, vis);
                }
            }
            
        }
    }
    void solve(vector<vector<char>>& board) 
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 || i == m-1 || j == 0 || j == n-1)
                {
                    if(!vis[i][j] && board[i][j] == 'O')
                    {
                        DFS(i, j, board, vis);
                    }
                }
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!vis[i][j] && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};
