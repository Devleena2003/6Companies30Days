class solution
{
public:
    void dfs(int i, int j, int &area, vector<vector<int>> &grid)
    {
        // if no condition is satisfied
        if (!(i >= 0 && i <= grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1))
            return;
        area++;                    // we increasing area after the function calling in main function
        grid[i][j] = 0;            // after visting we make it 0 to marks as visited
        dfs(i - 1, j, area, grid); // move top
        dfs(i, j + 1, area, grid); // move right
        dfs(i + 1, j, area, grid); // move down
        dfs(i, j - 1, area, grid); // move left
    }
    int maxAreaOfIsland(vector<vector<int>> grid)
    {
        int maxArea = 0;
        int area = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                { // if there is 1s then we called dfs and calculate maxarea
                    dfs(i, j, area, grid);
                    maxArea = max(maxArea, area);
                    area = 0;
                }
            }
        }
        return maxArea;
    }
}