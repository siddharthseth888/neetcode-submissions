class Solution {
public:

    void DFS(int i, int j, vector<vector<char>>& grid)
    {
        grid[i][j] = 'visited';
        int m = grid.size();
        int n = grid[0].size();
        if(i-1 >= 0 &&  grid[i-1][j] == '1')
        {
            DFS(i-1, j, grid);
        }
        if(j+1 < n && grid[i][j+1] == '1')
        {
            DFS(i, j+1, grid);
        }
        if(i+1 < m && grid[i+1][j] == '1')
        {
            DFS(i+1, j, grid);
        }
        if(j-1 >= 0 && grid[i][j-1] == '1')
        {
            DFS(i, j-1, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int island = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1')
                {
                    DFS(i, j, grid);
                    island++;
                }
            }
        }

        return island;
        
    }
};
