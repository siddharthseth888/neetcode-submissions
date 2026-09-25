class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0;

        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        //In the queue I have all the rotten fruits
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
            }
        }

        vector<pair<int,int>> dirs = {{-1,0}, {0, 1}, {1,0}, {0,-1}};
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++)
                {
                    int nr = r + dirs[i].first;
                    int nc = c + dirs[i].second;

                    if(nr >= 0 && nr < m && nc >= 0 && nc < n)
                    {
                        if(grid[nr][nc] == 1)
                        {
                            grid[nr][nc] = 2;
                            q.push({nr, nc});
                        }   
                    }
                }

            }

            if(!q.empty()) {
                minutes++;
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return minutes;
    }
};
