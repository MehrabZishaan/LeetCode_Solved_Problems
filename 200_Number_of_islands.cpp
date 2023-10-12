// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/

class Solution
{
public:
    int numIslands(std::vector<std::vector<char>> &grid)
    {
        int count = 0;
        int rows = grid.size();
        if (rows == 0)
            return 0;
        int cols = grid[0].size();

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] == '1')
                {
                    count += 1;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }

private:
    void dfs(std::vector<std::vector<char>> &grid, int i, int j)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0')
        {
            return;
        }

        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};