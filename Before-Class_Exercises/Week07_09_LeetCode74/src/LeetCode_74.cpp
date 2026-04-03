// Email: s1131456@mail.yzu.edu.tw
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 取得矩陣的欄數與列數
        int len = matrix[0].size();
        int row = matrix.size();

        // 從最後一列開始向上遍歷
        for (int i = row - 1; i >= 0; i--) {
            // 如果該列第一個數字就大於target，則整列都不可能包含目標
            if (matrix[i][0] > target) {
                continue;
            }
            
            // 在鎖定的列中進行線性搜尋
            for (int j = 0; j < len; j++) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        
        // 未找到回傳 false
        return false;
    }
};