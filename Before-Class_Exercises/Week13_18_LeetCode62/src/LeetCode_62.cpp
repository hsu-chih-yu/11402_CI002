// Email: s1131456@mail.yzu.edu.tw
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 建立 m x n 的二維陣列，並將所有初始值設為 1
        // 因為第一列與第一行的路徑數永遠為 1，這樣寫可以直接完成初始化
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        // 從索引 (1, 1) 開始計算其餘格子的路徑數
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // 狀態轉移：當前格子的路徑數 = 上方格子來源 + 左方格子來源
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        // 回傳右下角的數值即為總路徑數
        return dp[m-1][n-1];
    }
};