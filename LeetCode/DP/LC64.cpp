// 最小路径和 https://leetcode.cn/problems/minimum-path-sum/

class Solution { // y总写法，下标从1开始，不用考虑边界问题，只要注意初始化好就行
public:
    int minPathSum(vector<vector<int>>& grid) {

        // f[i][j] 表示从左上角走到 (i, j) 经过路径上数字总和的最小值
        int f[210][210];
        memset(f, 0x3f, sizeof f);
        f[0][1] = 0; // 这里初始化f[1][0]也可以

        int m = grid.size(), n = grid[0].size();
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i - 1][j - 1];        
        return f[m][n];
    }
};

class Solution { // 正常写法，需要考虑边界问题
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(!i && !j) continue;
                if(!i && j) grid[i][j] = grid[i][j - 1]  + grid[i][j];
                else if(i && !j) grid[i][j] = grid[i - 1][j] + grid[i][j];
                else grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];    
            }
               
        return grid[m - 1][n - 1];
    }
};