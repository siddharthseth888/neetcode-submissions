class Solution {
public:
    int DFS(int i, int j, vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        grid[i][j] = 0;
        int area = 0;
        if(i-1 >= 0 && grid[i-1][j])
        {
            area += 1+DFS(i-1, j, grid);
        }
        if(j+1 < n && grid[i][j+1])
        {
            area += 1+DFS(i, j+1, grid);
        }
        if(i+1 < m && grid[i+1][j])
        {
            area += 1+DFS(i+1, j, grid);
        }
        if(j-1 >= 0 && grid[i][j-1])
        {
            area += 1+DFS(i, j-1, grid);
        }

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j])
                {
                    maxi = max(maxi, 1+DFS(i, j, grid));
                }
            }
        }

        return maxi;
    }
};
