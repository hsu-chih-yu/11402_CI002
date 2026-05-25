// Email: s1131456@mail.yzu.edu.tw#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 1. 初始化第一列（只能從左邊來）
        for(int j = 1; j < n; j++){
            grid[0][j] += grid[0][j-1];
        }

        // 2. 初始化第一行（只能從上面來）
        for(int i = 1; i < m; i++){
            grid[i][0] += grid[i - 1][0];
        }

        // 3. 填充剩餘格子的 DP 值
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                // 抵達 (i, j) 的成本 = 當前值 + min(上方來源, 左方來源)
                grid[i][j] += min(grid[i - 1][j], grid[i][j-1]);
            }
        }

        // 4. 右下角即為最終解答
        return grid[m - 1][n - 1];
    }
};