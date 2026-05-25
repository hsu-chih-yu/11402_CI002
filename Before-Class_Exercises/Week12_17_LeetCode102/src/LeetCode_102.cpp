// Email: s1131456@mail.yzu.edu.tw
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * LeetCode 110 - Balanced Binary Tree
 * 邏輯：由底向上檢查高度，若不平衡則回傳 -1 進行剪枝
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // 若最終回傳值不是 -1，代表整棵樹皆符合平衡條件
        return checkHeight(root) != -1;
    }

private:
    int checkHeight(TreeNode* node) {
        // 1. 基礎情況：空節點高度為 0
        if (node == nullptr) return 0;

        // 2. 遞迴檢查左子樹
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1; // 左子樹不平衡，直接向上回報

        // 3. 遞迴檢查右子樹
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1; // 右子樹不平衡，直接向上回報

        // 4. 檢查當前節點是否平衡
        if (abs(leftHeight - rightHeight) > 1) {
            return -1; // 左右高度差超過 1，標記為不平衡
        }

        // 5. 若平衡，回傳當前節點的實際高度
        return max(leftHeight, rightHeight) + 1;
    }
};