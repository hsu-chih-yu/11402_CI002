// Email: s1131456@mail.yzu.edu.tw
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // 複製原始矩陣 (利用 vector 的賦值運算子進行深拷貝)
        vector<vector<int>> copy = matrix;
        
        // 進行座標轉換
        // 規則：旋轉 90 度後，原本位於 [i][j] 的元素會跑到 [j][n - 1 - i]
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 將 copy 中的舊值填入 matrix 的新位置
                // 原始的第一列 (i=0) 會填入最後一行 (Column = n-1)
                matrix[j][n - 1 - i] = copy[i][j];
            }
        }
    }
};